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

int n, m, x, a[maxn];

int main() {
    n = read(), m = read();
    for (rei i = 1; i <= n; ++i) a[i] = read();
    while (m--) {
        x = read();
        rei l = 1, r = n, mid;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (a[mid] < x)
                l = mid + 1;
            else
                r = mid;
        }
        if (a[l] == x)
            printf("%d ", l);
        else
            printf("-1 ");
    }
    // system("pause");
    return 0;
}
