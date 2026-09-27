#include <stdio.h>
#include <time.h>

int main(void) {
    clock_t start, stop;
    double duration;

    start = clock();
    /* 被测代码 */
    stop = clock();

    duration = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("duration = %f s\n", duration);
    return 0;
}