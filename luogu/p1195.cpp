// 并查集 kruskal解最小生成树
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n, m, k, cnt, sum, fa[1005];

struct Edge {
    int u, v, w;
    bool operator<(const Edge &edge) const {
        return w < edge.w;
    }
} e[10005];

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

void join(int x, int y, int w) {
    int f1 = find(x), f2 = find(y);
    if (f1 != f2) {
        fa[f1] = f2;
        sum += w;
        ++cnt;
    }
}

void kruskal() {
    sum = cnt = 0;
    for (int i = 1; i <= m; ++i) {
        join(e[i].u, e[i].v, e[i].w);
        if (cnt == n - k) {
            printf("%d\n", sum);
            return;
        }
    }
    printf("No Answer\n");
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i) fa[i] = i;
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
    }
    sort(e + 1, e + 1 + m);
    kruskal();
    return 0;
}
