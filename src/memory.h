#include <stdint.h>

#include "src/L2/network.h"
#include "src/type.h"

typedef struct queues QUEUES;

typedef struct m_hdr {
    struct mbuf *mh_next;
    struct mbuf *mh_nextpkt;
    uint32_t mh_len;
    void *mh_data;
    uint16_t mh_type;
    uint16_t mh_flags;
} M_HDR;

typedef struct pkthdr {
    uint32_t len;
    IFNET *recvif;
} PKTHDR;

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
#define m_nextpkt m_hdr.mh_nextpkt
#define m_act m_nextpkt
#define m_pkthdr M_dat.MH.MH_pkthdr
#define m_ext M_dat.MH.MH_dat.MH_ext
#define m_pktdat M_dat.MH.MH_dat.MH_databuf
#define m_dat M_dat.M_databuf

extern int QueueInitTest(QUEUES *queues);