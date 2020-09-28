// 离散化, 线段树
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
#define maxn 1000005
#define ll long long
#define ull unsigned long long
using namespace std;

int c, n, tot = 0, ans = 0, li[maxn], ri[maxn], a[maxn], flag[maxn];
bool vis[maxn];

inline int lc(int p) { return p << 1; }
inline int rc(int p) { return p << 1 | 1; }

void push_down(int p) {
    if (flag[p] != -1) {
        flag[lc(p)] = flag[p];
        flag[rc(p)] = flag[p];
        flag[p] = -1;
    }
}

void update(int p, int l, int r, int x, int y, int k) {
    if (x <= l && r <= y) {
        flag[p] = k;
        return;
    }
    push_down(p);
    int mid = (l + r) >> 1;
    if (x <= mid) update(lc(p), l, mid, x, y, k);
    if (y > mid) update(rc(p), mid + 1, r, x, y, k);
}

void query(int p, int l, int r) {
    if (flag[p] != -1 && !vis[flag[p]]) {
        ++ans;
        vis[flag[p]] = 1;
        return;
    }
    if (l == r) return;
    push_down(p);
    int mid = (l + r) >> 1;
    query(lc(p), l, mid);
    query(rc(p), mid + 1, r);
}

int main() {
    scanf("%d", &c);
    while (c--) {
        // init
        memset(flag, -1, sizeof(flag));
        memset(vis, 0, sizeof(vis));
        ans = 0;

        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", li + i, ri + i);
            a[tot++] = li[i];
            a[tot++] = ri[i];
        }
        sort(a, a + tot);
        tot = unique(a, a + tot) - a;
        int tmp = tot;
        for (int i = 1; i < tmp; ++i) {
            if (a[i] - a[i - 1] > 1) {
                a[tot++] = a[i - 1] + 1;
            }
        }
        sort(a, a + tot);
        for (int i = 0; i < n; ++i) {
            int x = lower_bound(a, a + tot, li[i]) - a;
            int y = lower_bound(a, a + tot, ri[i]) - a;
            update(1, 0, tot - 1, x, y, i);
        }
        query(1, 0, tot - 1);
        printf("%d\n", ans);
    }
    // system("pause");
    return 0;
}
