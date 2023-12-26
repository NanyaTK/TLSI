#include <stdint.h>
#include <stdio.h>

#include "src/L2/interfaces/dummy.h"
#include "src/L2/network.h"
#include "src/OS/os.h"
#include "src/util.h"

int main(void) {
    OSInit();
    IFNET *interface;
    interface = DummyInit();
    if (!interface) {
        errorf("DummyInit() failure");
        return -1;
    }
    IFNETOutput(interface, "asd", "asdf");
    return 0;
}