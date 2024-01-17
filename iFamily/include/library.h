/****
 *
 * Copyright(C) 2022-2024 MiracleForest Studio. All Rights Reserved.
 *
 * @Filename: library.h
 * @CreationTime: 2024.1.17.18:06
 * @Creator: Lovelylavender4
 * -----------------------------------------------------------------------------
 * The file defines some macros related to the library.
 * -----------------------------------------------------------------------------
 * If you discover any bugs,
 * you can provide feedback to us on GitHub or via email at MiracleForest@Outlook.com!
 * We will definitely strive to do better!
 *
 ****/
#pragma once

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
