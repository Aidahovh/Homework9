#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 3

void *print_numbers(void *arg) {
    int id = *(int *)arg;
    for (int i = 1; i <= 5; i++) {
        printf("Thread %d: %d\n", id, i);
        usleep(1000); /* small delay so interleaving is visible */
    }
    return NULL;
}

int main(void) {
    pthread_t th[NUM_THREADS];
    int ids[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        ids[i] = i + 1;
        pthread_create(&th[i], NULL, print_numbers, &ids[i]);
    }
    for (int i = 0; i < NUM_THREADS; i++)
        pthread_join(th[i], NULL);

    return 0;
}
