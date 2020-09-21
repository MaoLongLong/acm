#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define pi acos(-1.0)
#define maxn 20005
#define maxw 20005
#define ll long long
#define ull unsigned long long
#define re register
#define il inline
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

int n, m, w, x, y, pre[maxn], wt[maxn], vl[maxn], dp[maxw];

int find(int x) { return x == pre[x] ? x : pre[x] = find(pre[x]); }

void join(int x, int y) {
    int f1 = find(x), f2 = find(y);
    if (f1 != f2) {
        pre[f1] = f2;
    }
}

int main() {
    n = read(), m = read(), w = read();
    for (int i = 1; i <= n; ++i) wt[i] = read(), vl[i] = read(), pre[i] = i;
    while (m--) {
        x = read(), y = read();
        join(x, y);
    }
    for (int i = 1; i <= n; ++i) {
        if (pre[i] != i) {
            wt[find(i)] += wt[i];
            vl[find(i)] += vl[i];
            wt[i] = vl[i] = 0;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = w; j >= wt[i]; --j) {
            dp[j] = max(dp[j], dp[j - wt[i]] + vl[i]);
        }
    }
    printf("%d\n", dp[w]);
    system("pause");
    return 0;
}
