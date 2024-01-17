/****
 *
 * Copyright(C) 2022-2024 MiracleForest Studio. All Rights Reserved.
 *
 * @Filename: compiler.h
 * @CreationTime: 2024.1.17.18:06
 * @Creator: Lovelylavender4
 * -----------------------------------------------------------------------------
 * The file defines some macros related to the compiler.
 * -----------------------------------------------------------------------------
 * If you discover any bugs,
 * you can provide feedback to us on GitHub or via email at MiracleForest@Outlook.com!
 * We will definitely strive to do better!
 *
 ****/
#pragma once

#if defined(__ICC) || defined(__INTEL_COMPILER)
#    define __ICC__                      __INTEL_COMPILER
#    define __CURRENT_COMPILER_NAME__    "ICC"
#    define __CURRENT_COMPILER_VERSION__ __ICC__
#elif defined(__clang__)
#    define __CLANG__                    __clang_version__
#    define __CURRENT_COMPILER_NAME__    "CLANG"
#    define __CURRENT_COMPILER_VERSION__ __CLANG__
#elif defined(__GNUC__) || defined(__GNUG__)
#    define __GCC__ 1
#    define __GCCV__                                                                                         \
        std::to_string(__GNUC__) + "." + std::to_string(__GNUC_MINOR__) + "."                                \
            + std::to_string(__GNUC_PATCHLEVEL__)
#    define __CURRENT_COMPILER_NAME__    "GCC"
#    define __CURRENT_COMPILER_VERSION__ __GCCV__
#elif defined(__HP_cc) || defined(__HP_aCC)
#    define __HP__                       true
#    define __CURRENT_COMPILER_NAME__    "HP"
#    define __CURRENT_COMPILER_VERSION__ 0
#elif defined(__IBMCPP__)
#    define __ILECPP__                   __IBMCPP__
#    define __CURRENT_COMPILER_NAME__    "ILECPP"
#    define __CURRENT_COMPILER_VERSION__ __ILECPP__
#elif defined(_MSC_VER)
#    define __MSVC__                     _MSC_VER
#    define __CURRENT_COMPILER_NAME__    "MSVC"
#    define __CURRENT_COMPILER_VERSION__ __MSVC__
#elif defined(__PGI)
#    define __PGCPP__                    __PGI
#    define __CURRENT_COMPILER_NAME__    "PGCPP"
#    define __CURRENT_COMPILER_VERSION__ __PGCPP__
#elif defined(__SUNPRO_CC)
#    define __SUNPRO__                   __SUNPRO_CC
#    define __CURRENT_COMPILER_NAME__    "SUNPRO"
#    define __CURRENT_COMPILER_VERSION__ __SUNPRO__
#else
#    define __UNKNOWN__                  true
#    define __CURRENT_COMPILER_NAME__    "UNKNOWN"
#    define __CURRENT_COMPILER_VERSION__ __UNKNOWN__
#endif
