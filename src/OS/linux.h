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
 * linux.h
 * header of linux.c
 */

#ifndef LINUX_H
#define LINUX_H

#include <stddef.h>
#include <stdlib.h>
#ifdef __linux__
#include <pthread.h>
#include <sys/time.h>
#endif

#include "src/OS/os.h"
#include "src/type.h"

//
extern OSFunctionTable *LinuxGetFunctionTable();

/*
 * Initialize
 */
extern void LinuxInit();

/*
 * Memory
 */
extern void *LinuxMemoryAlloc(size_t size);
extern void LinuxMemoryFree(void *ptr);

/*
 * Time
 */
extern TIME LinuxGetLocalTime();

extern void LinuxFLockFile(FILE *file);
extern void LinuxFunLockFile(FILE *file);

/*
 * mutex
 */
extern void *LinuxMutexInit(void *lock);
extern void LinuxMutexLock(void *lock);
extern void LinuxMutexUnlock(void *lock);

#endif