#include <bits/stdc++.h>
using namespace std;

const int N = 200000 + 5;
const int M = N * 25;   // 大约 n * log n

int a[N], b[N];
int root[N];
int ls[M], rs[M], sum[M];
int idx;

// 在上一版本 pre 的基础上，新插入一个位置 pos
int insert(int pre, int l, int r, int pos) {
    int now = ++idx;

    ls[now] = ls[pre];
    rs[now] = rs[pre];
    sum[now] = sum[pre] + 1;

    if (l == r) return now;

    int mid = (l + r) >> 1;

    if (pos <= mid)
        ls[now] = insert(ls[pre], l, mid, pos);
    else
        rs[now] = insert(rs[pre], mid + 1, r, pos);

    return now;
}

// 查询区间 [l, r] 中第 k 小
// 这里 u = root[l - 1], v = root[r]
int query(int u, int v, int l, int r, int k) {
    if (l == r) return l;

    int mid = (l + r) >> 1;

    // [l, mid] 内有多少个元素
    int cnt = sum[ls[v]] - sum[ls[u]];

    if (k <= cnt)
        return query(ls[u], ls[v], l, mid, k);
    else
        return query(rs[u], rs[v], mid + 1, r, k - cnt);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    // 离散化
    sort(b + 1, b + n + 1);
    int len = unique(b + 1, b + n + 1) - b - 1;

    // 建立 n 个前缀版本
    for (int i = 1; i <= n; i++) {
        int pos = lower_bound(b + 1, b + len + 1, a[i]) - b;
        root[i] = insert(root[i - 1], 1, len, pos);
    }

    // m 次查询：l r k
    while (m--) {
        int l, r, k;
        cin >> l >> r >> k;

        int pos = query(root[l - 1], root[r], 1, len, k);

        // pos 是离散化后的下标，还原为原值
        cout << b[pos] << '\n';
    }

    return 0;
}