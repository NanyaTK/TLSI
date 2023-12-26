#include "src/L2/interfaces/loopback.h"
#include "src/L2/network.h"
#include "src/OS/os.h"
#include "src/type.h"
#include "src/util.h"

int main(void) {
    OSInit();
    IFNET *interface;
    interface = IFNETAlloc();
    if (!interface) {
        errorf("IFNETAlloc() failure");
        return -1;
    }
    interface = LoopbackInit();
    interface->if_func->if_output(interface, 0, "192.168.0.1");
    return 0;
}