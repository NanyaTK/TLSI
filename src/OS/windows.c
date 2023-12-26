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

#include "windows.h"

#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

OSFunctionTable *WIN32GetFunctionTable() {
    static OSFunctionTable t = {
        WIN32Init,         WIN32MemoryAlloc, WIN32MemoryFree,
        WIN32GetLocalTime, WIN32FLockFile,   WIN32FunLockFile,
    };
    return &t;
}

void WIN32Init(void) {
    fprintf(stderr, "  =======================================\n");
    fprintf(stderr, "  |  OSInit -> WindowsInit was called   |\n");
    fprintf(stderr, "  |  OS type was registered as Windows  |\n");
    fprintf(stderr, "  =======================================\n");
}

void *WIN32MemoryAlloc(size_t size) { return calloc(1, size); }
void WIN32MemoryFree(void *ptr) { free(ptr); }

/*
 * Return local time
 */
TIME WIN32GetLocalTime(void) {
    SYSTEMTIME st;
    TIME time;
    GetLocalTime(&st);
    time.year = st.wYear;
    time.month = st.wMonth;
    time.day = st.wDay;
    time.hour = st.wHour;
    time.minute = st.wMinute;
    time.second = st.wSecond;
    time.milliseconds = st.wMilliseconds;
    return time;
}

/*
 * file
 */
void WIN32FLockFile(FILE *file) { _lock_file(file); }
void WIN32FunLockFile(FILE *file) { _unlock_file(file); }