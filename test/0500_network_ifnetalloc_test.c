#include <stdint.h>
#include <stdio.h>

#include "../src/L2/network.h"
#include "../src/OS/os.h"
#include "../src/util.h"
#include "src/type.h"

int main(void) {
    OSInit();
    IFNET *interface;
    interface = IFNETAlloc();
    interface->if_type = IF_TYPE_DUMMY;
    debugf("debug%s", interface->if_name);
}