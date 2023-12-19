#include <stdint.h>
#include <stdio.h>

#include "src/OS/os.h"
#include "src/memory.h"
#include "src/util.h"

int main(void) {
    OSInit();
    QUEUES *queues;
    queues = OSMemoryAlloc(sizeof(queues));
    if (QueueInitTest(queues) == -1) {
        errorf("QueueInitTest() failure");
    } else {
        infof("QueuInitTest was successfully finished.");
    }
}