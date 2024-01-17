#include "9902_pointer.h"

#include <stdint.h>
#include <stdio.h>

int Pointer2(void *mutex) {
    int hoge = 3;
    mutex = &hoge;
    return 0;
}

int main(void) {
    void *mutex;

    Pointer2(mutex);
    fprintf(stderr, "%p\n", mutex);

    return 0;
}
