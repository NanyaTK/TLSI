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

#include "OS/windows.h"

#include <malloc.h>
#include <stdlib.h>

OSFunctionTable *WIN32GetFunctionTable() {
    static OSFunctionTable t = {
        WIN32Init,
        WIN32MemoryAlloc,
        WIN32MemoryFree,
    };
    return &t;
}

void WIN32Init() {}

void *WIN32MemoryAlloc(size_t size) { return calloc(1, size); }
void WIN32MemoryFree(void *ptr) { free(*ptr); }