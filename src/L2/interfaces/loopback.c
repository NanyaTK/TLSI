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

#include "loopback.h"

#include <stdint.h>
#include <stdio.h>

#include "../../type.h"
#include "../../util.h"
#include "../network.h"

static int LoopbackOutput(IFNET *interface, const uint8_t *data,
                          const void *dst) {
    debugf("LoopbackOutput() called");
    return 0;
}

static IFFUNC loopbackfunc = {
    .if_output = LoopbackOutput,
};

IFNET *LoopbackInit() {
    IFNET *interface;
    interface = IFNETAlloc();
    if (!interface) {
        errorf("IFNETAlloc() failure");
        return NULL;
    }
    interface->if_type = IF_TYPE_LOOPBACK;
    interface->if_func = &loopbackfunc;
    return interface;
}