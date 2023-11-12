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

#include "linux.h"

#include <stddef.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>

#include "os.h"

OSFunctionTable *LinuxGetFunctionTable() {
    static OSFunctionTable t = {
        LinuxInit,         LinuxMemoryAlloc, LinuxMemoryFree,
        LinuxGetLocalTime, LinuxFLockFile,   LinuxFunLockFile,
    };
    return &t;
}

void LinuxInit() {
    fprintf(stderr, "  =====================================\n");
    fprintf(stderr, "  |  OSInit -> LinuxInit was called   |\n");
    fprintf(stderr, "  |  OS type was registered as Linux  |\n");
    fprintf(stderr, "  =====================================\n");
}

void *LinuxMemoryAlloc(size_t size) { return calloc(1, size); }
void LinuxMemoryFree(void *ptr) { free(ptr); }

TIME LinuxGetLocalTime() {
    TIME time;
    struct timeval tv;
    struct tm *tm;

    gettimeofday(&tv, NULL);
    tm = localtime(&tv.tv_sec);
    time.year = tm->tm_year + 1900;
    time.month = tm->tm_mon + 1;
    time.day = tm->tm_mday;
    time.hour = tm->tm_hour;
    time.minute = tm->tm_min;
    time.second = tm->tm_sec;
    time.milliseconds = (unsigned int)(tv.tv_usec / 1000);
    return time;
}

void LinuxFLockFile(FILE *file) { flockfile(file); }
void LinuxFunLockFile(FILE *file) { funlockfile(file); }