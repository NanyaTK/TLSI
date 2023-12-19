#include <stdio.h>

#include "../src/OS/os.h"

int main(void) {
    OSInit();
    OSFLockFile(stderr);
    fprintf(stderr,"flockfile\n");
    OSFunLockFile(stderr);
}