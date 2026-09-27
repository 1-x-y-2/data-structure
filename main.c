#include <stdio.h>

int MaxSubseqSum(int A[], int N) {
    int ThisSum = 0;
    int MaxSum = 0;

    for (int i = 0; i < N; i++) {
        ThisSum += A[i];

        if (ThisSum > MaxSum) {
            MaxSum = ThisSum;
        } else if (ThisSum < 0) {
            ThisSum = 0;
        }
    }

    return MaxSum;
}

int main(void) {
    int nums[] = {4, -3, 5, -2, -1, 2, 6, -2};

    int n = sizeof(nums) / sizeof(nums[0]);

    printf("%d\n", MaxSubseqSum(nums, n));
    return 0;
}