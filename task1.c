#include <stdio.h>
#include <pthread.h>

void *run(void *arg) {
    int id = *(int *)arg;
    printf("Thread %d is running (pthread ID: %lu)\n", id, (unsigned long)pthread_self());
    return NULL;
}

int main(void) {
    pthread_t threads[3];
    int ids[3];

    for (int i = 0; i < 3; i++) {
        ids[i] = i + 1;
        pthread_create(&threads[i], NULL, run, &ids[i]);
    }
    for (int i = 0; i < 3; i++)
        pthread_join(threads[i], NULL);

    printf("All threads completed. Main exiting.\n");
    return 0;
}
