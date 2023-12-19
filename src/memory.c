#include "src/memory.h"

MBUF mbuf;
typedef struct queues {
    MBUF *head;
    MBUF *tail;
} QUEUES;

int QueueInitTest(QUEUES *queues) {
    queues->head = NULL;
    queues->tail = NULL;
    return 0;
}