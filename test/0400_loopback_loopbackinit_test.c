#include "../src/L2/interfaces/loopback.h"
#include "../src/L2/network.h"
#include "../src/OS/os.h"
#include "../src/util.h"

int main(void) {
    IFNET *interface;
    OSInit();
    interface = LoopbackInit();
    if (!interface) {
        errorf("LoopbackInit() failure");
        return -1;
    }
    debugf("if_type=%zu", interface->if_type);
    return 0;
}