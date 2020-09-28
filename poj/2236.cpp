// 并查集, 提高
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 1005;
typedef pair<int, int> node;

int n, d, x, y, len = 0, pre[maxn], flag[maxn];
char op;
node pos[maxn];

int find(int i) { return i == pre[i] ? i : pre[i] = find(pre[i]); }

void join(int i, int j) {
    int f1 = find(i), f2 = find(j);
    if (f1 != f2) {
        pre[f1] = f2;
    }
}

int main() {
    // freopen("1(1).in", "r", stdin);
    // freopen("1.out", "w", stdout);
    scanf("%d%d", &n, &d);
    for (int i = 1; i <= n; ++i) pre[i] = i;
    d *= d;
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &x, &y);
        pos[i] = make_pair(x, y);
    }
    while (~scanf(" %c", &op)) {
        if (op == 'O') {
            scanf("%d", &x);
            flag[++len] = x;
            // 只有已经标记过的才可能连通
            for (int i = 1; i < len; ++i) {
                int ox = pos[flag[i]].first - pos[flag[len]].first;
                int oy = pos[flag[i]].second - pos[flag[len]].second;
                if (ox * ox + oy * oy <= d) {
                    join(flag[i], flag[len]);
                }
            }
        } else {
            scanf("%d%d", &x, &y);
            if (find(x) == find(y))
                printf("SUCCESS\n");
            else
                printf("FAIL\n");
        }
    }
    // system("pause");
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}
