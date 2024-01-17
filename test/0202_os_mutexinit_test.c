#include <stdio.h>

#include "src/OS/os.h"

int main(void) {
    OSInit();
    void *lock;
    lock = OSLockInit(lock);
    return 0;
}