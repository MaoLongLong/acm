#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define pi acos(-1.0)
#define maxn 500005
#define ll long long
#define ull unsigned long long
#define re register
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

int n, m, op, x, y, a[maxn];

inline int lowbit(int x) { return x & -x; }

inline void add(int x, int k) {
    while (x <= n) {
        a[x] += k;
        x += lowbit(x);
    }
}

inline int sum(int x) {
    int ans = 0;
    while (x > 0) {
        ans += a[x];
        x -= lowbit(x);
    }
    return ans;
}

int main() {
    n = read(), m = read();
    for (re int i = 1; i <= n; ++i) {
        x = read();
        add(i, x);
    }
    while (m--) {
        op = read(), x = read(), y = read();
        if (op == 1)
            add(x, y);
        else
            printf("%d\n", sum(y) - sum(x - 1));
    }
    // system("pause");
    return 0;
}
