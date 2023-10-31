#include <stdint.h>
#include <stdio.h>

#include "../src/L2/network.h"
#include "../src/OS/os.h"
#include "../src/util.h"

int main(void) {
    OSInit();
    IFNET *interface;
    interface = ifnet_alloc();
    interface->if_name = "adsf";
    debugf("asdf%s", interface->if_name);
}