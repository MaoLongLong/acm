// 线段树， 状态压缩
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#define maxn 100005
#define mid int m = (l + r) >> 1
#define lson rt << 1, l, m
#define rson rt << 1 | 1, m + 1, r
using namespace std;

int n, t, o, x, y, c, lazy[maxn << 2], color[maxn << 2];
char op;

inline void push_up(int rt) {
    color[rt] = color[rt << 1] | color[rt << 1 | 1];
}

inline void push_down(int rt) {
    if (lazy[rt]) {
        lazy[rt << 1] = lazy[rt << 1 | 1] = lazy[rt];
        color[rt << 1] = color[rt << 1 | 1] = lazy[rt];
        lazy[rt] = 0;
    }
}

inline void build(int rt, int l, int r) {
    if (l == r) {
        color[rt] = 1;
        return;
    }
    mid;
    build(lson);
    build(rson);
    push_up(rt);
}

inline void update(int rt, int l, int r, int x, int y, int c) {
    if (x <= l && r <= y) {
        color[rt] = 1 << (c - 1);
        lazy[rt] = 1 << (c - 1);
        return;
    }
    push_down(rt);
    mid;
    if (x <= m) update(lson, x, y, c);
    if (y > m) update(rson, x, y, c);
    push_up(rt);
}

inline int query(int rt, int l, int r, int x, int y) {
    if (x <= l && r <= y) return color[rt];
    push_down(rt);
    mid;
    int sum = 0;
    if (x <= m) sum |= query(lson, x, y);
    if (y > m) sum |= query(rson, x, y);
    return sum;
}

int main() {
    scanf("%d%d%d", &n, &t, &o);
    build(1, 1, n);
    memset(lazy, 0, sizeof(lazy));
    while (o--) {
        scanf(" %c", &op);
        if (op == 'C') {
            scanf("%d%d%d", &x, &y, &c);
            if (x > y) swap(x, y);
            update(1, 1, n, x, y, c);
        } else {
            scanf("%d%d", &x, &y);
            if (x > y) swap(x, y);
            int sum = query(1, 1, n, x, y), ans;
            for (ans = 0; sum; ++ans) sum &= (sum - 1);
            printf("%d\n", ans);
        }
    }
    // system("pause");
    return 0;
}
