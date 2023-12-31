#include "src/OS/os.h"
#include "src/memory.h"
#include "src/util.h"

int main(void) {
    OSInit();
    QUEUES *queues;
    MBUF *mbuf;
    MBUFEX *mbufex;

    queues = OSMemoryAlloc(sizeof(*queues));
    mbuf = OSMemoryAlloc(sizeof(mbuf));
    mbufex = OSMemoryAlloc(sizeof(*mbufex));
    if (QueueInit(queues) == -1) {
        errorf("QueueInitTest() failure");
    } else {
        infof("QueuInitTest was successfully finished.");
    }
    /*mbufex->mex_next = NULL;
    mbufex->mex_data = (char *)("mmbuffjfj");
    if (queues->tailex) {
        queues->tailex->mex_next = mbufex;
    }
    queues->tailex = mbufex;
    if (!queues->headex) {
        queues->headex = mbufex;
    }
    queues->num++;
    debugf("%s,%d", queues->headex->mex_data, queues->num);*/
    mbuf->m_len = 56;
    mbuf->m_data = "asdffsa";
    void *data = "mexsadfdjfask";
    debugf("%s", mbufex->mex_data);
    QueueEnqueue(queues, mbuf, 1);
    QueueEnqueue(queues, mbuf, 1);
    QueueEnqueue(queues, data, 2);
    QueueEnqueue(queues, mbuf, 1);
    debugf("%s,%d", queues->tail->m_data, queues->num);
}