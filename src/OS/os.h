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

typedef struct OSFunctionTable {
    void (*Init)(void);
    void *(*MemoryAlloc)(size_t size);
    void (*MemoryFree)(void *ptr);
} OSFunctionTable;

extern void OSInit(void);

// include the OS-specific header
#ifdef WIN32
#include "windows.h"
#elif __linux__  // linux
#include "linux.h"
#else  // WIN32 and linux
#include "unix.h"
#endif  // WIN32

#endif  // OS_H