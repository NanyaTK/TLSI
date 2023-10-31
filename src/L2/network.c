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

#include "network.h"

#include <stdint.h>
#include <stdio.h>

#include "../OS/os.h"
#include "../util.h"

IFNET *interfaces;
IFADDR *addrlists;

IFNET *ifnet_alloc(void) {
    IFNET *interface;
    interface = OSMemoryAlloc(sizeof(*interface));
    if (!interface) {
        errorf("OSMemoryAlloc() failure");
        return NULL;
    }
    interface->if_index = 3232;
    return interface;
}

int ifnet_free(void *interface) {
    OSMemoryFree(interface);
    if (interface) {
        errorf("OSMemoryFree() failure");
        return -1;
    }
    return 0;
}
