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

#include "os.h"

#include <stdio.h>

#include "../type.h"
#include "linux.h"
#include "unix.h"
#include "windows.h"

static OSFunctionTable *os = NULL;

void OSInit(void) {
#ifdef _WIN32
    os = WIN32GetFunctionTable();
#elif __linux__
    os = LinuxGetFunctionTable();
#else
    os = UnixGetFunctionTable();
#endif

    os->Init();
}

int GetOsType(int ostype) {
#if WIN32
    ostype = OS_TYPE_WIN32;
#elif __linux__
    ostype = OS_TYPE_LINUX;
#else
    ostype = OS_TYPE_UNIX;
#endif

    return ostype;
}

void *OSMemoryAlloc(size_t size) { return os->MemoryAlloc(size); }
void OSMemoryFree(void *ptr) { os->MemoryFree(ptr); }
TIME OSGetLocalTime(void) { return os->GetLocalTime(); }