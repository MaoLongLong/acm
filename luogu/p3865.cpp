#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define pi acos(-1.0)
#define maxn 100005
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

int n, m, l, r, st[maxn][21];

int main() {
    n = read(), m = read();
    for (re int i = 1; i <= n; ++i) st[i][0] = read();
    int log2N = log2(n);
    for (re int j = 1; j <= log2N; ++j) {
        for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    while (m--) {
        l = read(), r = read();
        int t = log2(r - l + 1);
        printf("%d\n", max(st[l][t], st[r - (1 << t) + 1][t]));
    }
    // system("pause");
    return 0;
}
