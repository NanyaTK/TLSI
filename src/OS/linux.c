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

#include "OS/linux.h"

#include <stddef.h>
#include <sys/time.h>

#include "os.h"

OSFunctionTable *LinuxGetFunctionTable() {
    static OSFunctionTable t = {
        LinuxInit,
        LinuxMemoryAlloc,
        LinuxMemoryFree,
    };
    return &t;
}

void LinuxInit() {}

void *LinuxMemoryAlloc(size_t size) { return calloc(1, size); }
void LinuxMemoryFree(void *ptr) { free(ptr); }