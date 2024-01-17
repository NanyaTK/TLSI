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
 * windows.h
 * Header of windows.c
 */

#ifndef WINDOWS_H
#define WINDOWS_H

#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "os.h"

//
extern OSFunctionTable *WIN32GetFunctionTable();

/*
 * Initialize
 */
extern void WIN32Init(void);

/*
 * Memory
 */
extern void *WIN32MemoryAlloc(size_t size);
extern void WIN32MemoryFree(void *ptr);

/*
 * Local Time
 */
extern TIME WIN32GetLocalTime(void);

/*
 * File
 */
extern void WIN32FLockFile(FILE *file);
extern void WIN32FunLockFile(FILE *file);

/*
 * Mutex
 */
extern void *WIN32Init(void *lock);
extern void WIN32Lock(void *lock);
extern void WIN32Unlock(void *lock);

#endif  // WINDOWS_H