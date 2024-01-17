/*
 * Copyright (C) 2023 NanyaTK ( https://github.com/NanyaTK )
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

/*
 * os.h
 * Header of os.c
 */
#ifndef OS_H
#define OS_H

#include <stdio.h>

#include "src/type.h"

struct TIME {
    short year;
    short month;
    short day;
    short hour;
    short minute;
    short second;
    short milliseconds;
};

struct OSFunctionTable {
    void (*Init)(void);
    void *(*MemoryAlloc)(size_t size);
    void (*MemoryFree)(void *ptr);
    TIME (*GetLocalTime)(void);
    void (*FLockFile)(FILE *file);
    void (*FunLockFile)(FILE *file);
    void *(*LockInit)(void *lock);
    void (*Lock)(void *lock);
    void (*Unlock)(void *lock);
};

extern void OSInit(void);
extern void *OSMemoryAlloc(size_t size);
extern void OSMemoryFree(void *ptr);
extern TIME OSGetLocalTime(void);
extern void OSFLockFile(FILE *file);
extern void OSFunLockFile(FILE *file);
extern void *OSLockInit(void *lock);
extern void OSLock(void *lock);
extern void OSUnlock(void *lock);

// include the OS-specific header
#ifdef _WIN32
#include "windows.h"
#elif __linux__  // linux
#include "linux.h"
#else  // WIN32 and linux
#include "unix.h"
#endif  // WIN32

#endif  // OS_H