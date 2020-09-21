#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define pi acos(-1.0)
#define maxn 100005
#define ll long long
#define ull unsigned long long
using namespace std;
int read() {
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
        x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
    return x * f;
}

int n, m, op, x, y, k, a[maxn];
ll sum[maxn << 2], lazy[maxn << 2];

// left child
inline int lc(int p) { return p << 1; }
// right child
inline int rc(int p) { return p << 1 | 1; }

inline void push_down(int p, int l, int r) {
    if (lazy[p]) {
        int mid = (l + r) >> 1;
        lazy[lc(p)] += lazy[p];
        lazy[rc(p)] += lazy[p];
        sum[lc(p)] += lazy[p] * (mid - l + 1);
        sum[rc(p)] += lazy[p] * (r - mid);
        lazy[p] = 0;
    }
}

inline void build(int p, int l, int r) {
    if (l == r) {
        sum[p] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(lc(p), l, mid);
    build(rc(p), mid + 1, r);
    sum[p] = sum[lc(p)] + sum[rc(p)];
}

inline void update(int p, int l, int r, int x, int y, int k) {
    if (x <= l && r <= y) {
        sum[p] += k * (r - l + 1);
        lazy[p] += k;
        return;
    }
    push_down(p, l, r);
    int mid = (l + r) >> 1;
    if (x <= mid) update(lc(p), l, mid, x, y, k);
    if (y > mid) update(rc(p), mid + 1, r, x, y, k);
    sum[p] = sum[lc(p)] + sum[rc(p)];
}

inline ll query(int p, int l, int r, int x, int y) {
    if (x <= l && r <= y) return sum[p];
    push_down(p, l, r);
    int mid = (l + r) >> 1;
    ll ans = 0;
    if (x <= mid) ans += query(lc(p), l, mid, x, y);
    if (y > mid) ans += query(rc(p), mid + 1, r, x, y);
    return ans;
}

int main() {
    n = read(), m = read();
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    build(1, 1, n);
    while (m--) {
        op = read();
        if (op == 1) {
            x = read(), y = read(), k = read();
            update(1, 1, n, x, y, k);
        } else {
            x = read(), y = read();
            printf("%lld\n", query(1, 1, n, x, y));
        }
    }
    // system("pause");
    return 0;
}
