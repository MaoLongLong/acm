#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn = 1e5 + 5;

int m, n, sum = 0, a[maxn], b[maxn];

int main() {
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; ++i) scanf("%d", a + i);
    for (int i = 0; i < n; ++i) scanf("%d", b + i);
    sort(a, a + m);
    for (int i = 0; i < n; ++i) {
        int pos = lower_bound(a, a + m, b[i]) - a;
        if (pos == 0) {
            sum += a[0] - b[i];
        } else if (pos == m) {
            sum += b[i] - a[m - 1];
        } else {
            sum += min(a[pos] - b[i], b[i] - a[pos - 1]);
        }
    }
    printf("%d\n", sum);
    // system("pause");
    return 0;
}
