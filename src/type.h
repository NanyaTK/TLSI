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

#endif