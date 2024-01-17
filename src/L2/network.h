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
 * network.h
 * header of network.c
 */
#ifndef NETWORK_H
#define NETWORK_H

#include <stdint.h>
#include <stdio.h>

#include "src/OS/os.h"
#include "src/type.h"

struct if_data {
    uint8_t ifi_type;
    uint8_t ifi_addrlen;
    uint8_t ifi_hdrlen;
    uint64_t ifi_mtu;
    uint64_t ifi_metric;
    uint64_t ifi_baudrate;
    uint64_t ifi_ipackets;
    uint64_t ifi_ierrors;
    uint64_t ifi_opackets;
    uint64_t ifi_oerrors;
    uint64_t ifi_ibytes;
    uint64_t ifi_obytes;
    uint64_t ifi_imcasts;
    uint64_t ifi_omcasts;
    TIME ifi_lastchange;
};

struct sockaddr {
    uint8_t sa_len;
    uint8_t sa_family;
    int8_t sa_data[14];
};

struct ifaddr {
    struct ifaddr *ifaddr_next;
    struct ifnet *ifa_ifp;
    SOCKADDR *ifa_addr;
    SOCKADDR *ifa_dstaddr;
};

struct ifnet {
    struct ifnet *if_next;
    IFADDR *if_addrlist;
    char if_name[16];
    int16_t if_unit;
    uint16_t if_index;
    int16_t if_flags; /* IFF */
    int16_t if_timer;
    int32_t if_pcount;
    char *if_bpf;

    /* */
    IF_DATA if_data;
    struct iffunc *if_func;
};

/* functions */
struct iffunc {
    // int (*if_init)(int);
    int (*if_input)(IFNET *ifp);
    int (*if_output)(IFNET *ifp, const uint8_t *data, const void *dst);
};

extern IFNET *IFNETAlloc(void);
extern int IFNETFree(void *interface);
extern int IFNETInterfacesRegister(IFNET *ifp);
extern int IFNETOutput(IFNET *ifp, const uint8_t *data, const void *dst);

#endif