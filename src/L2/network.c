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

#include "src/OS/os.h"
#include "src/type.h"
#include "src/util.h"

IFNET *interfaces;
IFADDR *addrlists;

IFNET *IFNETAlloc(void) {
    IFNET *interface;
    interface = OSMemoryAlloc(sizeof(*interface));
    if (!interface) {
        errorf("OSMemoryAlloc() failure");
        return NULL;
    }
    return interface;
}

int IFNETFree(void *interface) {
    OSMemoryFree(interface);
    if (interface) {
        errorf("OSMemoryFree() failure");
        return -1;
    }
    return 0;
}

/*
 * Initialize following values
 * if_index, if_name, if_next
 * And add interfaces.
 */
int IFNETInterfacesRegister(IFNET *ifp) {
    debugf("IFNETInterfaceRegister, if=0x%04x", ifp->if_flags);
    static uint32_t index = 0;
    ifp->if_index = index++;
    snprintf(ifp->if_name, sizeof(ifp->if_name), "net%d", ifp->if_index);
    ifp->if_next = interfaces;
    interfaces = ifp;
    return 0;
}

int IFNETOutput(IFNET *ifp, const uint8_t *data, const void *dst) {
    if (ifp->if_func->if_output(ifp, data, dst) == -1) {
        errorf("IF output failure()");
        return -1;
    }
    return 0;
}