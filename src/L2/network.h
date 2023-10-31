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

// #define IFF_BROADCAST
#define IFF_LOOPBACK 0x0001

typedef struct if_data {
    uint8_t ifi_type;
    uint8_t ifi_addrlen;
    uint8_t ifi_hdrlen;
    uint64_t ifi_mtu;
    uint64_t ifi_metric;
    uint64_t ifi_baudrate;
} IF_DATA;

typedef struct ifaddr {
    struct IFDEV *ifaddr_next;

} IFADDR;

typedef struct ifnet {
    struct ifnet *if_next;
    IFADDR *if_addrlist;
    char *if_name;
    int16_t if_unit;
    uint16_t if_index;
    int16_t if_flags; /* IFF */
    int16_t if_timer;
    int32_t if_pcount;
    char *if_bpf;

    /* */
    IF_DATA if_data;

} IFNET;

#define if_type if_data.ifi_type
#define if_addrlen if_data.ifi_addrlen
#define if_hdrlen if_data.ifi_hdrlen
#define if_mtu if_data.ifi_mtu
#define if_metric if_data.ifi_metric
#define if_baudrate if_data.ifi_baudrate

extern IFNET *ifnet_alloc(void);
extern int ifnet_free(void *interface);

#endif