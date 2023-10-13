#include <stdio.h>

#include "../src/OS/os.h"
int main(void) {
    // Windows
    TIME time;
    OSInit();
    time = OSGetLocalTime();
    printf("%02d:%02d:%02d.%03d\n", time.hour, time.minute, time.second,
           time.milliseconds);
    return 0;
}
