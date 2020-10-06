// 树状数组, dfs序
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 100005;
int n, m, u, v, x, cnt, head[maxn], vis[maxn], s[maxn], e[maxn], a[maxn], tr[maxn];
char op;

struct Edge {
    int to, next;
} edge[maxn << 1];

inline void add(int u, int v) {
    edge[++cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt;
}

void dfs(int p) {
    s[p] = ++cnt;
    vis[p] = 1;
    for (int i = head[p]; i; i = edge[i].next) {
        if (!vis[edge[i].to]) {
            dfs(edge[i].to);
        }
    }
    e[p] = cnt;
}

inline int lowbit(int x) { return x & -x; }

// 单点更新
inline void update(int x, int k) {
    while (x <= n) {
        tr[x] += k;
        x += lowbit(x);
    }
}

// 区间求和
inline int query(int x) {
    int sum = 0;
    while (x > 0) {
        sum += tr[x];
        x -= lowbit(x);
    }
    return sum;
}

void init() {
    for (int i = 1; i <= n; ++i) {
        head[i] = 0;
        vis[i] = 0;
        a[i] = 1;
        update(i, 1);
    }
}

int main() {
    scanf("%d", &n);
    init();
    cnt = 0;
    for (int i = 1; i < n; ++i) {
        scanf("%d%d", &u, &v);
        add(u, v);
        add(v, u);
    }
    cnt = 0;
    dfs(1);
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf(" %c%d", &op, &x);
        if (op == 'C') {
            if (a[x]) {
                a[x] = 0;
                update(s[x], -1);
            } else {
                a[x] = 1;
                update(s[x], 1);
            }
        } else {
            printf("%d\n", query(e[x]) - query(s[x] - 1));
        }
    }
    // system("pause");
    return 0;
}
