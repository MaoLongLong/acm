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
#define maxn 500005
#define ll long long
#define ull unsigned long long
#define lowbit(x) ((x) & (-x))
#define mid int m = (l + r) >> 1
#define lson rt << 1, l, m
#define rson rt << 1 | 1, m + 1, r
using namespace std;
inline int rd() {
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
    while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
    return x * f;
}

int n, m, op, x, y, k;
ll a[maxn] = {0};

inline void update(int x, int k) {
    while (x <= n) {
        a[x] += k;
        x += lowbit(x);
    }
}

inline ll query(int x) {
    ll ans = 0;
    while (x > 0) {
        ans += a[x];
        x -= lowbit(x);
    }
    return ans;
}

int main() {
    n = rd(), m = rd();
    x = 0;
    for (int i = 1; i <= n; ++i) {
        y = rd();
        update(i, y - x);
        x = y;
    }
    for (int i = 1; i <= m; ++i) {
        op = rd();
        if (op == 1) {
            x = rd(), y = rd(), k = rd();
            update(x, k);
            update(y + 1, -k);
        } else {
            x = rd();
            printf("%lld\n", query(x));
        }
    }
    // system("pause");
    return 0;
}
