#include <stdio.h>

#include "../src/util.h"

int main() {
    fprintf(stderr, "(%s:%d)\n", __FILE__, __LINE__);

    return 0;
}