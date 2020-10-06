// 线段树单点更新
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define mid int m = (l + r) >> 1
#define lson rt << 1, l, m
#define rson rt << 1 | 1, m + 1, r
#define maxn 200005
using namespace std;

int n, cnt[maxn << 2], ans[maxn << 2], pos[maxn], val[maxn];

inline void push_up(int rt) {
    cnt[rt] = cnt[rt << 1] + cnt[rt << 1 | 1];
}

inline void build(int rt, int l, int r) {
    cnt[rt] = r - l + 1;
    if (l == r) return;
    mid;
    build(lson);
    build(rson);
}

inline void update(int rt, int l, int r, int pos, int val) {
    if (l == r) {
        cnt[rt]--;
        ans[rt] = val;
        return;
    }
    mid;
    if (pos <= cnt[rt << 1])
        update(lson, pos, val);
    else
        update(rson, pos - cnt[rt << 1], val);
    push_up(rt);
}

inline void print_ans(int rt, int l, int r) {
    if (l == r) {
        printf("%d ", ans[rt]);
        return;
    }
    mid;
    print_ans(lson);
    print_ans(rson);
}

int main() {
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i)
            scanf("%d%d", pos + i, val + i);
        build(1, 1, n);
        for (int i = n - 1; i >= 0; --i)
            update(1, 1, n, pos[i] + 1, val[i]);
        print_ans(1, 1, n);
        putchar('\n');
    }
    // system("pause");
    return 0;
}
