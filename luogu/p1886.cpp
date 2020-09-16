#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define pi acos(-1.0)
#define maxn 1000005
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

int n, m, a[maxn];
int q[maxn]; // deque

void min_deque() {
    int h = 1, t = 0;
    for (re int i = 0; i < n; ++i) {
        while (h <= t && q[h] + m <= i) ++h;
        while (h <= t && a[q[t]] > a[i]) --t;
        q[++t] = i;
        if (i >= m - 1) printf("%d ", a[q[h]]);
    }
    printf("\n");
}

void max_deque() {
    int h = 1, t = 0;
    for (re int i = 0; i < n; ++i) {
        while (h <= t && q[h] + m <= i) ++h;
        while (h <= t && a[q[t]] < a[i]) --t;
        q[++t] = i;
        if (i >= m - 1) printf("%d ", a[q[h]]);
    }
    printf("\n");
}

int main() {
    n = read(), m = read();
    for (re int i = 0; i < n; ++i) a[i] = read();
    min_deque();
    max_deque();
    // system("pause");
    return 0;
}
