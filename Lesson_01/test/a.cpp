void fun(int n) {
    int i = 1;
    while (i <= n) {
        i *= 2;
    }
}

void fun(int n) {
    int i = 0;
    while (i * i * i <= n) {
        i++;
    }
}

for (int i = n - 1; i > 1; i--)
    for (int j = 1; j < i; j++)
        if (A[j] > A[j + 1])
            std::swap(A[j], A[j + 1]);

if (n >= 0) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            printf(">= 0\n");
} else {
    for (int j = 0; j < n; j++)
        printf("< 0\n");
}

int m = 0;
for (int i = 1; i <= n; i++)
    for (int j = 1; j <= 2 * i; j++)
        m++;

int Func(int n) {
    if (n == 1) return 1;
    else return 2 * Func(n / 2) + n;
}

int x = 2;
while (x < n / 2)
    x *= 2;

int fact(int n) {
    if (n <= 1) return 1;
    return n * fact(n - 1);
}

int count = 0;
for (int k = 1; k <= n; k *= 2)
    for (int j = 1; j <= n; j++)
        count++;
