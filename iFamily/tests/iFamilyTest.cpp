#include <iostream>
#include <shortcut.h>

int main()
{

    std::cout << "Hello World!\n";
    std::cout << "cxxstd: " << __CURRENT_CXXSTD_VERSION__ << "\n";
    std::cout << "compiler: " << __CURRENT_COMPILER_NAME__ << " " << __CURRENT_COMPILER_VERSION__ << "\n";
    std::cout << "platform: " << __CURRNET_PLATFORM__ << "\n";

    return 0;
}