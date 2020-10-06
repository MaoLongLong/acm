// 二维树状数组
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 1030;

int n, op, x, y, k, x1, x2, y1, y2, a[maxn][maxn], t[maxn][maxn];

inline int lowbit(int x) { return x & -x; }

inline void update(int x, int y, int k) {
    if (a[x][y] + k < 0) k = -a[x][y];
    a[x][y] += k;
    for (int i = x; i <= n; i += lowbit(i)) {
        for (int j = y; j <= n; j += lowbit(j)) {
            t[i][j] += k;
        }
    }
}

inline int query(int x, int y) {
    int sum = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
        for (int j = y; j > 0; j -= lowbit(j)) {
            sum += t[i][j];
        }
    }
    return sum;
}

int main() {
    while (scanf("%d", &op) && op != 3) {
        if (op == 0) {
            scanf("%d", &n);
            memset(t, 0, sizeof(t));
            memset(a, 0, sizeof(a));
        } else if (op == 1) {
            scanf("%d%d%d", &x, &y, &k);
            update(x + 1, y + 1, k);
        } else {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            printf("%d\n", query(x2 + 1, y2 + 1) - query(x1, y2 + 1) - query(x2 + 1, y1) + query(x1, y1));
        }
    }
    // system("pause");
    return 0;
}
