#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#define inf 0x3f3f3f3f
#define pi acos(-1.0)
#define maxn 5005
#define maxm 200005
#define ll long long
#define ull unsigned long long
#define re register
#define il inline
using namespace std;
il int read() {
    re int x = 0, f = 1;
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
    for (re int i = 1; i <= n; ++i) a[i] = i;
    sort(e, e + m, cmp);
    for (re int i = 0; i < m; ++i) {
        join(e[i].u, e[i].v, e[i].w);
        if (cnt == n - 1) break;
    }
}

int main() {
    n = read(), m = read();
    for (re int i = 0; i < m; ++i) {
        e[i].u = read();
        e[i].v = read();
        e[i].w = read();
    }
    kruskal();
    printf("%d\n", ans);
    // system("pause");
    return 0; }
