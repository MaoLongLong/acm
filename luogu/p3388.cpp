// 割点
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 100005;
int n, m, x, y, cnt = 0, head[maxn] = {0};
int tot = 0, dfn[maxn] = {0}, low[maxn] = {0}, idx = 0;
bool flag[maxn] = {0};

struct Edge {
    int v, next;
} e[maxn << 1];

void add(int u, int v) {
    e[++cnt].v = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void tarjan(int u, int r) {
    dfn[u] = low[u] = ++idx;
    int child = 0;
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].v;
        if (!dfn[v]) {
            tarjan(v, r);
            low[u] = min(low[u], low[v]);
            if (low[v] >= dfn[u] && u != r) flag[u] = 1;
            if (u == r) ++child;
        } else
            low[u] = min(low[u], dfn[v]);
    }
    if (child > 1 && u == r) flag[u] = 1;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &x, &y);
        add(x, y);
        add(y, x);
    }
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) {
            tarjan(i, i);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (flag[i]) {
            ++tot;
        }
    }
    printf("%d\n", tot);
    for (int i = 1; i <= n; ++i) {
        if (flag[i]) {
            printf("%d ", i);
        }
    }
    return 0;
}
