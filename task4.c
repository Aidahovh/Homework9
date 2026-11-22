#include <stdio.h>
#include <pthread.h>

#define N 5

void *square(void *arg) {
    int n = *(int *)arg;
    printf("Square of %d is %d\n", n, n * n);
    return NULL;
}

int main(void) {
    int nums[N] = {1, 2, 3, 4, 5};
    pthread_t th[N];

    for (int i = 0; i < N; i++)
        pthread_create(&th[i], NULL, square, &nums[i]);
    for (int i = 0; i < N; i++)
        pthread_join(th[i], NULL);

    return 0;
}
