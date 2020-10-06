// 并查集模板题
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 5005;
int n, m, p, x, y, fa[maxn];

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

void join(int x, int y) {
    int f1 = find(x), f2 = find(y);
    if (f1 != f2) {
        fa[f1] = f2;
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 1; i <= n; ++i) fa[i] = i;
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &x, &y);
        join(x, y);
    }
    for (int i = 1; i <= p; ++i) {
        scanf("%d%d", &x, &y);
        if (find(x) == find(y))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
