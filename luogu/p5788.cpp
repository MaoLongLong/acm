// 单调栈
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
#define maxn 3000005
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

int n, top, a[maxn], stk[maxn], ans[maxn];

int main() {
    n = rd();
    for (int i = 1; i <= n; ++i) a[i] = rd();
    top = 0, stk[top] = 0;
    for (int i = n; i > 0; --i) {
        while (top && a[stk[top]] <= a[i]) --top;
        ans[i] = stk[top];
        stk[++top] = i;
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d ", ans[i]);
    }
    return 0;
}
