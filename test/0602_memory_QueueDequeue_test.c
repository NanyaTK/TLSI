#include "src/OS/os.h"
#include "src/memory.h"
#include "src/util.h"

#define DEBUG

int main(void) {
    OSInit();
    QUEUES *queues;
    MBUF *mbuf;
    MBUFEX *mbufex;

    queues = OSMemoryAlloc(sizeof(*queues));
    mbuf = OSMemoryAlloc(sizeof(*mbuf));
    mbufex = OSMemoryAlloc(sizeof(*mbufex));
    if (QueueInit(queues) == -1) {
        errorf("QueueInitTest() failure");
    } else {
        infof("QueuInitTest was successfully finished.");
    }
    mbuf->m_len = 56;
    mbuf->m_data = "asdffsa";
    void *data = "mexsadfdjfask";
    // debugf("%s", mbufex->mex_data);
    for (int i = 0; i < 4; i++) {
        QueueEnqueue(queues, data, 2);
        QueueEnqueue(queues, mbuf, 1);
    }
    for (int i = 0; i < 8; i++) {
        MBUF *dequeuedata = QueueDequeue(queues);
        if (dequeuedata) {
            // infof("%d", i);
            debugf("%s,%d,%d,%d", dequeuedata->m_data, queues->num,
                   queues->headflag, queues->tailflag);
        }
    }

    for (int i = 0; i < 4; i++) {
        QueueEnqueue(queues, mbuf, 1);
        QueueEnqueue(queues, data, 2);
    }
    for (int i = 0; i < 8; i++) {
        MBUF *dequeuedata = QueueDequeue(queues);
        if (dequeuedata) {
            // infof("%d", i);
            debugf("%s,%d,%d,%d", dequeuedata->m_data, queues->num,
                   queues->headflag, queues->tailflag);
        }
    }
}