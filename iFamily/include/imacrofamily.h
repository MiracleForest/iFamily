/****
 *
 * Copyright(C) 2022-2024 MiracleForest Studio. All Rights Reserved.
 *
 * @Filename: imacrofamily.h
 * @CreationTime: 2022.5.2.17:09
 * @Creator: Lovelylavender4
 * -----------------------------------------------------------------------------
 * This file defines some global macros, aliases, etc.,
 * and will be referenced by almost all projects of Miracle Forest Studio.
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

/*------------------------Determine which compiler is being used------------------------*/
#if defined(__ICC) || defined(__INTEL_COMPILER)
#    define __ICC__ __INTEL_COMPILER
#elif defined(__clang__)
#    define __CLANG__ __clang_version__
#elif defined(__GNUC__) || defined(__GNUG__)
#    define __GCC__ 1
#    define __GCCV__                                                                                         \
        std::to_string(__GNUC__) + "." + std::to_string(__GNUC_MINOR__) + "."                                \
            + std::to_string(__GNUC_PATCHLEVEL__)
#elif defined(__HP_cc) || defined(__HP_aCC)
#    define __HP__ true
#elif defined(__IBMCPP__)
#    define __ILECPP__ __IBMCPP__
#elif defined(_MSC_VER)
#    define __MSVC__ _MSC_VER
#elif defined(__PGI)
#    define __PGCPP__ __PGI
#elif defined(__SUNPRO_CC)
#    define __SUNPRO__ __SUNPRO_CC
#else
#    define __UNKNOWN__ true
#endif

/*------------------------Determine which C++ standard is being used------------------------*/
#if !defined(__CPP_23__) && !defined(__CPP_20__) && !defined(__CPP_17__) && !defined(__CPP_14__)             \
    && !defined(__CPP_11__)
#    if _HAS_CXX23
#        define __CPP_23__ true
#        define __CPP_20__ true
#        define __CPP_17__ true
#        define __CPP_14__ true
#        define __CPP_11__ true
#    elif _HAS_CXX20
#        define __CPP_20__ true
#        define __CPP_17__ true
#        define __CPP_14__ true
#        define __CPP_11__ true
#    elif _HAS_CXX17
#        define __CPP_17__ true
#        define __CPP_14__ true
#        define __CPP_11__ true
#    elif _HAS_CXX14
#        define __CPP_14__ true
#        define __CPP_11__ true
#    else
#        define __CPP_11__ true
#    endif
#endif

/*------------------------Determine which platform is being used------------------------*/
#ifdef _WIN64
#    define __WIN64__ true
#endif
#ifdef _WIN32
#    define __WIN32__   true
#    define __WINDOWS__ true
#elif defined __linux__
#    define __LINUX__ true
#elif defined __APPLE__
#    define __APPLE__ true
#elif defined __unix__
#    define __UNIX__ true
#else
#    define __UNK__ true
#endif

/*------------------------Library-related content------------------------*/
#ifdef ___STATICLIB___
#    define IAPI
#elif defined(__MSVC__)

#    ifdef ___ILIBRARYEXPORT___
#        define IAPI _declspec(dllexport)
#    else
#        define IAPI _declspec(dllimport)
#    endif

#    define IAPI_EXPORT _declspec(dllexport)
#    define IAPI_IMPORT _declspec(dllimport)

#elif defined(__GCC__)
#    define IAPI __attribute__((visibility("default")))
#else
#    define IAPI
#endif

/*------------------------Others------------------------*/
#define CATCH(x)                                                                                             \
    catch (...) { printf(x); }
#define TCATCH(_try, x)                                                                                      \
    try                                                                                                      \
    {                                                                                                        \
        _try                                                                                                 \
    }                                                                                                        \
    catch (...)                                                                                              \
    {                                                                                                        \
        printf(x);                                                                                           \
    }
#define SPACE(namespaceName)       namespace namespaceName
#define SPACE_                     namespace
#define EXPRESSIONSWITHCOMMAS(...) __VA_ARGS__
#define EWC(...)                   __VA_ARGS__

/*------------------------Namespace------------------------*/
#define _ISTD i::core::

#include <cstdint>

SPACE_ MiracleForest::inline i
{
    SPACE(core)
    {

        using ushort = unsigned short;
        using sshort = signed short;
        using uint   = unsigned int;
        using sint   = signed int;
        using llong  = long long;
        using ulong  = unsigned long;
        using ullong = unsigned long long;
        using slong  = signed long;
        using sllong = signed long long;
        using uchar  = unsigned char;
        using schar  = signed char;
        using int64  = long long;
        using uint64 = unsigned long long;

        using __unk_type_v__ = void*;
        using unkTypev       = void*;
        using unkPtr         = void*;
        using anyPtr         = void*;
        using handle         = void*;
        using wchar          = wchar_t;

        using _BYTE  = uchar;
        using _WORD  = ushort;
        using _DWORD = uint;
        using _QWORD = uint64;

#if !defined(_MSC_VER)
#    define _OWORD __int128
#endif

        using VA  = uint64;
        using RVA = uint;

        template<typename _Type>
        using Ptr = _Type*;

        template<typename _Type>
        using PPtr = _Type**;

        template<typename _Type>
        using CPtr = const _Type*;

        template<typename _Type>
        using CPPtr = const _Type**;

        template<typename _Type>
        using CRef = const _Type&;

        template<typename _Type>
        using CRRef = const _Type&&;

        template<typename _Type>
        using Ref = _Type&;

        template<typename _Type>
        using RRef = _Type&&;

        template<typename _Type>
        struct stdcall_cast_s;

        template<typename _Type>
        struct cdecl_cast_s;

        template<typename _Type>
        struct fastcall_cast_s;

        template<typename _Type>
        struct thiscall_cast_s;

        template<typename _RetTy, typename... _ArgTy>
        struct stdcall_cast_s<_RetTy(_ArgTy...)>
        {
            using type = _RetTy(__stdcall*)(_ArgTy...);
        };

        template<typename _RetTy, typename... _ArgTy>
        struct cdecl_cast_s<_RetTy(_ArgTy...)>
        {
            using type = _RetTy(__cdecl*)(_ArgTy...);
        };

        template<typename _RetTy, typename... _ArgTy>
        struct fastcall_cast_s<_RetTy(_ArgTy...)>
        {
            using type = _RetTy(__fastcall*)(_ArgTy...);
        };

        template<typename _RetTy, typename... _ArgTy>
        struct thiscall_cast_s<_RetTy(_ArgTy...)>
        {
            using type = _RetTy(__thiscall*)(_ArgTy...);
        };

        template<typename _Func>
        using stdcall_cast = typename stdcall_cast_s<_Func>::type;

        template<typename _Func>
        using cdecl_cast = typename cdecl_cast_s<_Func>::type;

        template<typename _Func>
        using fastcall_cast = typename fastcall_cast_s<_Func>::type;

        template<typename _Func>
        using thiscall_cast = typename thiscall_cast_s<_Func>::type;

    } // SPACE(core)
} // SPACE(i)