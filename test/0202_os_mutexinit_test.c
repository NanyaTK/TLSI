#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#include "src/OS/os.h"
#include "src/util.h"

int global_val = 0;
void *mutex = NULL;

void *thread_start_routine(void *arg) {
    int i;
    for (i = 0; i < 100000; i++) {
        OSLock(mutex);
        // pthread_mutex_lock(&mutex);
        global_val++;
        OSUnlock(mutex);
        // pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    int i;
    pthread_t th;
    void *th_ret;

    OSInit();
    mutex = OSLockInit(mutex);
    // pthread_mutex_init(&mutex, NULL);
    if (pthread_create(&th, NULL, thread_start_routine, NULL)) {
        perror("pthread_create");
        return 1;
    }

    for (i = 0; i < 100000; i++) {
        OSLock(mutex);
        // pthread_mutex_lock(&mutex);
        global_val++;
        OSUnlock(mutex);
        // pthread_mutex_unlock(&mutex);
    }

    if (pthread_join(th, &th_ret) != 0) {
        perror("pthread_join");
        return 1;
    }
    debugf("%d", global_val);

    return 0;
}