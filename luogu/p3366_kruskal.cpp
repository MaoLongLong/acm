#include <bits/stdc++.h>
#define maxn 5005
#define maxm 200005
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

struct Edge {
    int u, v, w;
} e[maxm];

int n, m, ans, cnt, a[maxn];

bool cmp(Edge e1, Edge e2) { return e1.w < e2.w; }

int find(int x) { return x == a[x] ? x : a[x] = find(a[x]); }

void join(int u, int v, int w) {
    int f1 = find(u), f2 = find(v);
    if (f1 != f2) {
        a[f1] = f2;
        ans += w;
        ++cnt;
    }
}

void kruskal() {
    for (int i = 1; i <= n; ++i) a[i] = i;
    sort(e, e + m, cmp);
    for (int i = 0; i < m && cnt < n; ++i) {
        join(e[i].u, e[i].v, e[i].w);
    }
}

int main() {
    n = read(), m = read();
    for (int i = 0; i < m; ++i) {
        e[i].u = read();
        e[i].v = read();
        e[i].w = read();
    }
    kruskal();
    printf("%d\n", ans);
    // system("pause");
    return 0;
}
