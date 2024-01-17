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
 * util.h
 * header of util.c
 */
#ifndef UTIL_H
#define UTIL_H

#include <stdarg.h>
#include <stdio.h>

#include "src/OS/os.h"
#include "src/type.h"

/*
 * Log
 */
extern void Logprintf(FILE *fp, int logtype, const char *file, int line,
                      const char *func, const char *fmt, ...);
/*
#if defined(__C99__FUNC__)
#define MACRO_FUNC __func__
#elif defined(__FUNCTION__)  // __C99__FUNC__
#define MACRO_FUNC __FUNCTION__
#else  // __FUNCTION__
#define MACRO_FUNC "Function name unavailable"
#endif  // __FUNCTION
*/

#define MACRO_FUNC __func__

#define debugf(...) \
    Logprintf(stderr, 'D', __FILE__, __LINE__, MACRO_FUNC, __VA_ARGS__)
#define errorf(...) \
    Logprintf(stderr, 'E', __FILE__, __LINE__, MACRO_FUNC, __VA_ARGS__)
#define infof(...) \
    Logprintf(stderr, 'I', __FILE__, __LINE__, MACRO_FUNC, __VA_ARGS__)

#endif