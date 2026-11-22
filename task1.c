#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 3

void *run(void *arg) {
    int id = *(int *)arg;
    printf("Thread %d is running (pthread ID: %lu)\n", id, (unsigned long)pthread_self());
    return NULL;
}

int main(void) {
    pthread_t threads[NUM_THREADS];
    int ids[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        ids[i] = i + 1;
        pthread_create(&threads[i], NULL, run, &ids[i]);
    }
    for (int i = 0; i < NUM_THREADS; i++)
        pthread_join(threads[i], NULL);

    printf("All threads completed. Main exiting.\n");
    return 0;
}
