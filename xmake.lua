add_rules("mode.debug", "mode.release")

add_repositories("MiF-repo https://github.com/MiracleForest/xmake-repo.git")

target("iFamilyTests")
    set_kind("binary")
    add_files("iFamily/tests/**.cpp")
    add_headerfiles(
        "iFamily/include/**.h"
    )
    add_includedirs(
        "iFamily/include"
    )
    add_cxxflags(
        "/utf-8",
        "/permissive-",
        "/EHa",
        "/W4",
        "/w44265",
        "/w44289",
        "/w44296",
        "/w45263",
        "/w44738",
        "/w45204"
    )
    add_defines(
        "_CRT_SECURE_NO_WARNINGS",
        "_ENABLE_CONSTEXPR_MUTEX_CONSTRUCTOR",
        "NOMINMAX",
        "UNICODE",
        "WIN32_LEAN_AND_MEAN"
    )
    set_languages("c++20")
target_end()