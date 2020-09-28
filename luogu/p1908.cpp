#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 5;
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

struct node {
    int val, idx;
} a[maxn];

bool cmp(node n1, node n2) {
    return n1.val >= n2.val;
}

int n, b[maxn];
ll ans;

inline int lowbit(int x) { return x & -x; }

inline void update(int x, int k) {
    while (x <= n) {
        b[x] += k;
        x += lowbit(x);
    }
}

inline int query(int x) {
    int sum = 0;
    while (x > 0) {
        sum += b[x];
        x -= lowbit(x);
    }
    return sum;
}

int main() {
    n = read();
    for (int i = 1; i <= n; ++i) {
        a[i].val = read();
        a[i].idx = i;
    }
    stable_sort(a + 1, a + 1 + n, cmp);
    ans = 0;
    for (int i = 1; i <= n; ++i) {
        update(a[i].idx, 1);
        ans += query(a[i].idx - 1);
    }
    printf("%lld\n", ans);
    // system("pause");
    return 0;
}
