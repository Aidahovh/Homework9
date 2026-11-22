#include <stdio.h>
#include <pthread.h>

int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

typedef struct { int start, end, id; long sum; } Task;

void *partial_sum(void *arg) {
    Task *t = (Task *)arg;
    t->sum = 0;
    for (int i = t->start; i < t->end; i++)
        t->sum += arr[i];
    printf("Thread %d: sum of arr[%d..%d] = %ld\n", t->id, t->start, t->end - 1, t->sum);
    return NULL;
}

int main(void) {
    int size = sizeof(arr) / sizeof(arr[0]);
    pthread_t th[2];
    Task tasks[2] = {{0, size / 2, 1, 0}, {size / 2, size, 2, 0}};

    for (int i = 0; i < 2; i++)
        pthread_create(&th[i], NULL, partial_sum, &tasks[i]);
    for (int i = 0; i < 2; i++)
        pthread_join(th[i], NULL);

    printf("Total sum = %ld\n", tasks[0].sum + tasks[1].sum);
    return 0;
}
