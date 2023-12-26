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

typedef struct if_data {
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
} IF_DATA;

typedef struct sockaddr {
    uint8_t sa_len;
    uint8_t sa_family;
    int8_t sa_data[14];
} SOCKADDR;

typedef struct ifaddr {
    struct ifaddr *ifaddr_next;
    struct ifnet *ifa_ifp;
    SOCKADDR *ifa_addr;
    SOCKADDR *ifa_dstaddr;
} IFADDR;

typedef struct ifnet {
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

} IFNET;

/* functions */
typedef struct iffunc {
    // int (*if_init)(int);
    int (*if_input)(IFNET *ifp);
    int (*if_output)(IFNET *ifp, const uint8_t *data, const void *dst);
} IFFUNC;

#define if_type if_data.ifi_type
#define if_addrlen if_data.ifi_addrlen
#define if_hdrlen if_data.ifi_hdrlen
#define if_mtu if_data.ifi_mtu
#define if_metric if_data.ifi_metric
#define if_baudrate if_data.ifi_baudrate
#define if_ipackets if_data.ifi_ipackets
#define if_ierrors if_data.ifi_ierrors
#define if_opackets if_data.ifi_opackets
#define if_ibytes if_data.ifi_ibytes
#define if_obytes if_data.ifi_obytes
#define if_imcasts if_data.ifi_imcasts
#define if_omcasts if_data.ifi_omcasts
#define if_lastchange if_data.ifi_lastchange

extern IFNET *IFNETAlloc(void);
extern int IFNETFree(void *interface);
extern int IFNETInterfacesRegister(IFNET *ifp);
extern int IFNETOutput(IFNET *ifp, const uint8_t *data, const void *dst);


#endif