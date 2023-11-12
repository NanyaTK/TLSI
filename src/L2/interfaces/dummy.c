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
#include "dummy.h"

#include <stdint.h>
#include <stdio.h>

#include "src/L2/network.h"
#include "src/OS/os.h"
#include "src/type.h"
#include "src/util.h"

static int DummyOutput(IFNET *ifp, const uint8_t *data, const void *dst) {
    debugf("IFNET=%s", ifp->if_name);
    return 0;
}

static IFFUNC dummy_funcs = {
    .if_output = DummyOutput,
};

IFNET *DummyInit(void) {
    IFNET *ifnet;
    ifnet = IFNETAlloc();
    if (!ifnet) {
        errorf("IFNETAlloc() failure");
        return NULL;
    }
    debugf("IFNETAlloc");
    ifnet->if_type = IF_TYPE_DUMMY;
    ifnet->if_addrlen = 0;
    ifnet->if_hdrlen = 0;
    ifnet->if_mtu = 1500;
    ifnet->if_func = &dummy_funcs;
    if (IFNETInterfacesRegister(ifnet) == -1) {
        errorf("IFNETInterfacesRegister() failure");
        return NULL;
    }
    debugf("Initialized,interface=%s", ifnet->if_name);
    return ifnet;
}