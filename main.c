#include <stdio.h>

void Print(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(void) {
    int nums[10] = {1, 3, 2, 9, 8, 6, 7, 4, 10, 5};

    int n = sizeof(nums) / sizeof(nums[0]);

    for (int i = 0; i < n; i++) {
        int min = nums[i];
        int pos = i;
        for (int j = i; j < n; j++) {
            if (nums[j] < min) {
                min = nums[j];
                pos = j;
            }
        }
        int t = nums[i];
        nums[i] = nums[pos];
        nums[pos] = t;
    }

    Print(nums, n);

    return 0;
}