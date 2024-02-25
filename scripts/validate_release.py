import argparse
import re
import subprocess
from typing import TypedDict


class Args(TypedDict):
    tag: str


def main():
    args = get_args()

    version = args["tag"].lstrip("v")

    validate_changelog(version)


def get_args() -> Args:
    parser = argparse.ArgumentParser()
    parser.add_argument("--tag", required=True)

    args = parser.parse_args()

    return {
        "tag": args.tag,
    }


def validate_changelog(version: str):
    try:
        subprocess.run(
            f"npx changelog --format markdownlint",
            shell=True,
            check=True,
        )
    except subprocess.CalledProcessError as e:
        print("Have you installed it by `npm i -g keep-a-changelog`?")
        raise e

    with open("CHANGELOG.md", "r", encoding="utf-8") as f:
        content = f.read()

    if not re.search(r"## \[{}\]".format(version), content):
        raise Exception("CHANGELOG.md lacks version {}".format(version))


if __name__ == "__main__":
    main()
