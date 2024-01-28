/****
 *
 * Copyright(C) 2022-2024 MiracleForest Studio. All Rights Reserved.
 *
 * @Filename: aliases.h
 * @CreationTime: 2024.1.17.18:13
 * @Creator: Lovelylavender4
 * -----------------------------------------------------------------------------
 * The file defines some aliases.
 * -----------------------------------------------------------------------------
 * If you discover any bugs,
 * you can provide feedback to us on GitHub or via email at MiracleForest@Outlook.com!
 * We will definitely strive to do better!
 *
 ****/
#pragma once
#include <cstdint>

namespace MiracleForest::inline i
{
using ushort  = unsigned short;
using sshort  = signed short;
using uint    = unsigned int;
using sint    = signed int;
using llong   = long long;
using ulong   = unsigned long;
using ullong  = unsigned long long;
using slong   = signed long;
using sllong  = signed long long;
using uchar   = unsigned char;
using schar   = signed char;
using wchar   = wchar_t;
using u8char  = char8_t;
using u16char = char16_t;
using char8   = u8char;
using char16  = u16char;
using int64   = long long;
using uint64  = unsigned long long;

using __unk_type_v__ = void*;
using unkTypev       = void*;
using unkPtr         = void*;
using anyPtr         = void*;
using handle         = void*;

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
} // namespace MiracleForest::inline i