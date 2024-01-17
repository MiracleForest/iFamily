/****
 *
 * Copyright(C) 2022-2024 MiracleForest Studio. All Rights Reserved.
 *
 * @Filename: cxxstd.h
 * @CreationTime: 2024.1.17.18:06
 * @Creator: Lovelylavender4
 * -----------------------------------------------------------------------------
 * The file defines some macros related to the C++ standard.
 * -----------------------------------------------------------------------------
 * If you discover any bugs,
 * you can provide feedback to us on GitHub or via email at MiracleForest@Outlook.com!
 * We will definitely strive to do better!
 *
 ****/
#pragma once

#ifdef _MSVC_LANG
#    define _STL_LANG _MSVC_LANG
#elif defined(__cplusplus) // ^^^ use _MSVC_LANG / use __cplusplus vvv
#    define _STL_LANG __cplusplus
#else // ^^^ use __cplusplus / no C++ support vvv
#    define _STL_LANG 0L
#endif // ^^^ no C++ support ^^^

#ifndef _HAS_CXX14
#    if _STL_LANG > 201108L
#        define _HAS_CXX14 true
#    else
#        define _HAS_CXX14 false
#    endif
#endif // _HAS_CXX14

#ifndef _HAS_CXX17
#    if _STL_LANG > 201402L
#        define _HAS_CXX17 true
#    else
#        define _HAS_CXX17 false
#    endif
#endif // _HAS_CXX17

#ifndef _HAS_CXX20
#    if _HAS_CXX17 && _STL_LANG > 201703L
#        define _HAS_CXX20 true
#    else
#        define _HAS_CXX20 false
#    endif
#endif // _HAS_CXX20

#ifndef _HAS_CXX23
#    if _HAS_CXX20 && _STL_LANG > 202002L
#        define _HAS_CXX23 true
#    else
#        define _HAS_CXX23 false
#    endif
#endif // _HAS_CXX23

#undef _STL_LANG

#if _HAS_CXX20 && !_HAS_CXX17
#    error _HAS_CXX20 must imply _HAS_CXX17.
#endif

#if _HAS_CXX23 && !_HAS_CXX20
#    error _HAS_CXX23 must imply _HAS_CXX20.
#endif

#if !defined(__CPP_23__) && !defined(__CPP_20__) && !defined(__CPP_17__) && !defined(__CPP_14__)             \
    && !defined(__CPP_11__)
#    if _HAS_CXX23
#        define __CURRENT_CXXSTD_VERSION__ "cxx23"
#        define __CPP_23__ true
#        define __CPP_20__ true
#        define __CPP_17__ true
#        define __CPP_14__ true
#        define __CPP_11__ true
#    elif _HAS_CXX20
#        define __CURRENT_CXXSTD_VERSION__ "cxx20"
#        define __CPP_20__ true
#        define __CPP_17__ true
#        define __CPP_14__ true
#        define __CPP_11__ true
#    elif _HAS_CXX17
#        define __CURRENT_CXXSTD_VERSION__ "cxx17"
#        define __CPP_17__ true
#        define __CPP_14__ true
#        define __CPP_11__ true
#    elif _HAS_CXX14
#        define __CURRENT_CXXSTD_VERSION__ "cxx14"
#        define __CPP_14__ true
#        define __CPP_11__ true
#    else
#        define __CURRENT_CXXSTD_VERSION__ "cxx11"
#        define __CPP_11__ true
#    endif
#endif
