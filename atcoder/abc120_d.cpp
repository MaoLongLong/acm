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
#define maxn 100005
#define ll long long
#define ull unsigned long long
#define lowbit(x) ((x) & (-x))
#define mid int m = (l + r) >> 1
#define lson rt << 1, l, m
#define rson rt << 1 | 1, m + 1, r
using namespace std;
int rd() {
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
    while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
    return x * f;
}

int n, m, fa[maxn];
ll sum, cnt[maxn], ans[maxn];

struct Edge {
    int u, v;
} e[maxn];

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

void merge(int x, int y) {
    int f1 = find(x), f2 = find(y);
    if (f1 != f2) {
        sum += 1LL * cnt[f1] * (cnt[f1] - 1) / 2;
        sum += 1LL * cnt[f2] * (cnt[f2] - 1) / 2;
        sum -= 1LL * (cnt[f1] + cnt[f2]) * (cnt[f1] + cnt[f2] - 1) / 2;
        fa[f1] = f2;
        cnt[f2] += cnt[f1];
    }
}

int main() {
    n = rd(), m = rd();
    sum = 1LL * n * (n - 1) / 2;
    for (int i = 0; i <= n; ++i) fa[i] = i, cnt[i] = 1;
    for (int i = 1; i <= m; ++i) e[i].u = rd(), e[i].v = rd();
    for (int i = m; i > 0; --i) {
        ans[i] = sum;
        merge(e[i].u, e[i].v);
    }
    for (int i = 1; i <= m; ++i) printf("%lld\n", ans[i]);
    return 0;
}
