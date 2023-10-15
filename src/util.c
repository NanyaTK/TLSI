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

#include "util.h"

#include <stdarg.h>
#include <stdio.h>

#include "OS/os.h"

/*
 * Log
 */
void Logprintf(FILE *fp, int logtype, const char *file, int line,
               const char *func, const char *fmt, ...) {
    TIME time;
    va_list ap;

    OSFLockFile(fp);
    time = OSGetLocalTime();
    fprintf(fp, "%d:%d:%d.%03d [%c] %s: ", time.hour, time.minute, time.second,
            time.milliseconds, logtype, func);
    va_start(ap, fmt);
    fprintf(fp, fmt, ap);
    va_end(ap);
    fprintf(fp, " (%s:%d)\n", file, line);
    OSFunLockFile(fp);
}