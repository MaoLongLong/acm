// 割边 (桥)
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 155;
int n, m, x, y, cnt = 0, head[maxn] = {0};
int dfn[maxn] = {0}, low[maxn] = {0}, idx = 0;
bool flag[maxn] = {0};

struct Edge {
    int u, v, next;
    bool operator<(const Edge &edge) const {
        if (u == edge.u) {
            return v < edge.v;
        }
        return u < edge.u;
    }
} e[10005], ans[10005];

void add(int u, int v) {
    e[++cnt].v = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

/**
 * tarjan算法求割边
 *
 * @param u cur node
 * @param f father
 */
void tarjan(int u, int f) {
    dfn[u] = low[u] = ++idx;
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].v;
        if (v == f) continue;
        if (!dfn[v]) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u]) {
                ans[++cnt].u = u;
                ans[cnt].v = v;
            }
        } else
            low[u] = min(low[u], dfn[v]);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &x, &y);
        add(x, y);
        add(y, x);
    }
    cnt = 0; // reset
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) {
            tarjan(i, i);
        }
    }
    sort(ans + 1, ans + 1 + cnt);
    for (int i = 1; i <= cnt; ++i) printf("%d %d\n", ans[i].u, ans[i].v);
    return 0;
}
