#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define mid int m = (l + r) >> 1
#define lson rt << 1, l, m
#define rson rt << 1 | 1, m + 1, r
#define inf 0x3f3f3f3f
using namespace std;
inline int rd() {
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}
const int maxn = 1e6 + 5;

int n, m, a[maxn], t[maxn];

inline void build(int rt, int l, int r) {
    if (l == r) {
        t[rt] = a[l];
        return;
    }
    mid;
    build(lson);
    build(rson);
    t[rt] = min(t[rt << 1], t[rt << 1 | 1]);
}

inline int query(int rt, int l, int r, int x, int y) {
    if (x <= l && r <= y) return t[rt];
    int low = inf, high = inf;
    mid;
    if (x <= m) low = query(lson, x, y);
    if (y > m) high = query(rson, x, y);
    return min(low, high);
}

int main() {
    n = rd(), m = rd();
    for (int i = 1; i <= n; ++i) a[i] = rd();
    build(1, 1, n);
    for (int i = 1; i <= n - m + 1; ++i) {
        printf("%d\n", query(1, 1, n, i, i + m - 1));
    }
    // system("pause");
    return 0;
}
