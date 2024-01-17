/****
 *
 * Copyright(C) 2022-2024 MiracleForest Studio. All Rights Reserved.
 *
 * @Filename: platform.h
 * @CreationTime: 2024.1.17.18:06
 * @Creator: Lovelylavender4
 * -----------------------------------------------------------------------------
 * The file defines some macros related to the platform.
 * -----------------------------------------------------------------------------
 * If you discover any bugs,
 * you can provide feedback to us on GitHub or via email at MiracleForest@Outlook.com!
 * We will definitely strive to do better!
 *
 ****/
#pragma once

#ifdef _WIN32
#    define __WIN32__            true
#    define __WINDOWS__          true
#    define __CURRNET_PLATFORM__ "WIN32"
#elif defined __linux__
#    define __LINUX__            true
#    define __CURRNET_PLATFORM__ "LINUX"
#elif defined __APPLE__
#    define __APPLE__            true
#    define __CURRNET_PLATFORM__ "APPLE"
#elif defined __unix__
#    define __UNIX__             true
#    define __CURRNET_PLATFORM__ "UNIX"
#else
#    define __UNK__              true
#    define __CURRNET_PLATFORM__ "UNK"
#endif

#ifdef _WIN64
#    undef __CURRNET_PLATFORM__
#    define __WIN64__            true
#    define __CURRNET_PLATFORM__ "WIN64"
#endif
