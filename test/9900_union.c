#include <stdint.h>
#include <stdio.h>

#include "src/OS/os.h"
#include "src/util.h"

#define MLEN 1500

typedef struct m_hdr {
    struct mbuf *mh_next;
    struct mbuf *mh_nextpkt;
    uint32_t mh_len;  // data length
    void *mh_data;    // data pointer
    uint16_t mh_type;
    uint16_t mh_flags;
} M_HDR;

typedef struct pkthdr {
    uint32_t len;
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

typedef struct mbuf2 {
    struct mbuf2 *m2_next;
    void *data;
} MBUF2;

typedef struct queues {
    union mbufhead {
        MBUF *head;
        MBUF2 *head2;
    } mbufhead;
    union {
        MBUF *tail;
        MBUF2 *tail2;
    } mbuftail;
    uint32_t num;
} QUEUES;

int main(void) {
    QUEUES *queue;
    MBUF2 *mbuf2;
    OSInit();
    queue = OSMemoryAlloc(sizeof(*queue));
    mbuf2 = OSMemoryAlloc(sizeof(*mbuf2));

    queue->mbufhead.head2 = NULL;
    queue->mbuftail.tail2 = NULL;
    queue->num = 0;

    mbuf2->m2_next = NULL;
    mbuf2->data = (char *)("asdf");
    if (queue->mbuftail.tail2) {
        queue->mbuftail.tail2->m2_next = mbuf2;
    }
    queue->mbuftail.tail2 = mbuf2;
    if (!queue->mbufhead.head2) {
        queue->mbufhead.head2 = mbuf2;
    }
    queue->num++;
    // debugf("%d", queue->mbufhead.head2->adffds);
    debugf("%s,%d", queue->mbufhead.head2->data, queue->num++);
}
