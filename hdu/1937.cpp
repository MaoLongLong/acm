// 前缀和, 尺取法
#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#define mem(a, v) memset(a, v, sizeof(a))
using namespace std;
const int MAXN = 305;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef unsigned long long ULL;

int r, c, k, st, en, cnt, ans, sum[MAXN][MAXN];
char a[MAXN][MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while (scanf("%d%d%d", &r, &c, &k) && (r || c || k)) {
        for (int i = 1; i <= r; ++i) scanf("%s", a[i] + 1);
        mem(sum, 0);
        ans = INF;
        for (int i = 1; i <= r; ++i) {
            for (int j = 1; j <= c; ++j) {
                sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
                if (a[i][j] == '.') {
                    sum[i][j]++;
                }
            }
        }
        // for (int i = 1; i <= r; ++i) {
        //     for (int j = 1; j <= c; ++j) {
        //         printf("%d ", sum[i][j]);
        //     }
        //     printf("\n");
        // }
        for (int i = r; i > 0; --i) {
            if (sum[i][c] < k) break;
            for (int j = 0; j < i; ++j) {
                if (sum[i][c] - sum[j][c] < k) break;
                st = 0, en = 1;
                while (en <= c || cnt >= k) {
                    cnt = sum[i][en] - sum[j][en] - sum[i][st] + sum[j][st];
                    if (cnt < k) {
                        en++;
                    } else {
                        ans = min(ans, (i - j) * (en - st));
                        st++;
                    }
                }
            }
        }
        printf("%d\n", ans);
    }

#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
