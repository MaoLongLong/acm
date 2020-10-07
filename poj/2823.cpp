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

int n, m, a[maxn], mi[maxn], ma[maxn], q[maxn];

void min_deque() {
// 1 3 -1 -3 5 3 6 7
    int h = 1, t = 0;
    for (int i = 1; i <= n; ++i) {
        while (h <= t && q[h] + m <= i) ++h;
        while (h <= t && a[q[t]] > a[i]) --t;
        q[++t] = i;
        if (i >= m) printf("%d ", a[q[h]]);
    }
    printf("\n");
}

void max_deque() {
    int h = 1, t = 0;
    for (int i = 1; i <= n; ++i) {
        while (h <= t && q[h] + m <= i) ++h;
        while (h <= t && a[q[t]] < a[i]) --t;
        q[++t] = i;
        if (i >= m) printf("%d ", a[q[h]]);
    }
    printf("\n");
}

int main() {
    n = rd(), m = rd();
    for (int i = 1; i <= n; ++i) a[i] = rd();
    min_deque();
    max_deque();
    return 0;
}
