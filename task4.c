#include <stdio.h>
#include <pthread.h>

void *square(void *arg) {
    int n = *(int *)arg;
    printf("Square of %d is %d\n", n, n * n);
    return NULL;
}

int main(void) {
    int nums[] = {1, 2, 3, 4, 5};
    int n = sizeof(nums) / sizeof(nums[0]);
    pthread_t th[5];

    for (int i = 0; i < n; i++)
        pthread_create(&th[i], NULL, square, &nums[i]);
    for (int i = 0; i < n; i++)
        pthread_join(th[i], NULL);

    return 0;
}
