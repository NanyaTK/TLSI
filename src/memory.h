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
 * memory.h
 * Header of memory.c
 */
#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>

#include "src/L2/network.h"
#include "src/OS/os.h"
#include "src/type.h"
#include "src/util.h"

/*
 * header of memory buffer
 */
typedef struct m_hdr {
    void *mh_next;     // chain
    struct mbuf *mh_nextpkt;  // packet
    uint32_t mh_len;          // data length
    void *mh_data;            // data pointer
    uint16_t mh_type;
    uint16_t mh_flags;
    uint8_t mh_nextflag;
} M_HDR;

typedef struct pkthdr {
    uint32_t len;
    IFNET *recvif;
} PKTHDR;

/*
 * extension buffer
 */
typedef struct m_ext {
    void *ext_buf;
    void (*ext_free)();
    uint32_t ext_size;
} M_EXT;

typedef struct mbuf {
    M_HDR m_hdr;
    union {
        struct {
            PKTHDR MH_pkthdr;
            union {
                M_EXT MH_ext;
                uint8_t MH_databuf[MLEN];
            } MH_dat;
        } MH;
        uint8_t M_databuf[MLEN];
    } M_dat;
} MBUF;

#define m_next m_hdr.mh_next
#define m_len m_hdr.mh_len
#define m_data m_hdr.mh_data
#define m_type m_hdr.mh_type
#define m_flags m_hdr.mh_flags
#define m_nextflag m_hdr.mh_nextflag
#define m_nextpkt m_hdr.mh_nextpkt
#define m_act m_nextpkt
#define m_pkthdr M_dat.MH.MH_pkthdr
#define m_ext M_dat.MH.MH_dat.MH_ext
#define m_pktdat M_dat.MH.MH_dat.MH_databuf
#define m_dat M_dat.M_databuf

typedef struct mbufex {
    void *mex_next;
    uint8_t mex_nextflag;
    void *mex_data;
} MBUFEX;

typedef struct queues {
    union {
        MBUF *head;
        MBUFEX *headex;
    };
    union {
        MBUF *tail;
        MBUFEX *tailex;
    };
    uint32_t num;
    uint8_t headflag;
    uint8_t tailflag;
} QUEUES;

extern int QueueInit(QUEUES *queues);
extern int QueueInitTest(QUEUES *queues);
extern void *QueueEnqueue(QUEUES *queues, void *data, uint8_t mbuftype);
extern void *QueueDequeue(QUEUES *queues);

#endif