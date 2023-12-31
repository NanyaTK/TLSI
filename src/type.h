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
 * type.h
 * define
 */

#ifndef TYPE_H
#define TYPE_H

#define OS_TYPE_LINUX 1
#define OS_TYPE_WIN32 2
#define OS_TYPE_UNIX 3

// ifnet->if_data.ifi_type
#define IF_TYPE_DUMMY 0x0000
#define IF_TYPE_LOOPBACK 0x0001
#define IF_TYPE_BROADCAST 0x0002
#define IF_TYPE_MULTICAST 0x0003
#define IF_TYPE_ETHERNET 0x0004

// ifnet->if_flags
#define IF_FLAG_UP 0x0001
#define IF_FLAG_LOOPBACK 0x0010
#define IF_FLAG_BROADCAST 0x0020

#define MSIZE 256
#define MLEN (MSIZE - sizeof(M_HDR))

#define M_FLAG_BCAST 0x0001
#define M_FLAG_EOR 0x0002
#define M_FLAG_EXT 0x0003
#define M_FLAG_MCAST 0x0004
#define M_FLAG_PKTHDR 0x0005
#define M_COPYFLAG \
    M_FLAG_BCAST | M_FLAG_EOR | M_FLAG_EXT | M_FLAG_MCAST | M_FLAG_PKTHDR

#define QUEUES_HEADFLAG_MBUF 1
#define QUEUES_HEADFLAG_MBUFEX 2
#define QUEUES_TAILFLAG_MBUF 1
#define QUEUES_TAILFLAG_MBUFEX 2

#endif