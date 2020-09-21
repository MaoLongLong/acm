#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define pi acos(-1.0)
#define maxn 1000005
#define ll long long
#define ull unsigned long long
#define rei register int
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

int n, c, a[maxn];
ll ans;

int main() {
    n = read(), c = read();
    for (rei i = 1; i <= n; ++i) a[i] = read();
    sort(a + 1, a + 1 + n);
    for (rei i = 1; i < n; ++i) {
        pair<int*, int*> p = equal_range(a + 1 + i, a + 1 + n, a[i] + c);
        ans += p.second - p.first;
    }
    printf("%lld\n", ans);
    // system("pause");
    return 0;
}
