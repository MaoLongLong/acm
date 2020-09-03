// 尺取法
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
const int MAXN = 100005;
const int INF = 0x3f3f3f3f;
typedef long long LL;

int n, k, l, r, st, en, a[MAXN];
LL t, ans, tmp, diff;
pair<LL, int> sum[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while (scanf("%d%d", &n, &k) && n + k) {
        sum[0] = make_pair(0, 0);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            sum[i] = make_pair(sum[i - 1].first + a[i], i);
        }
        sort(sum, sum + n + 1);
        while (k--) {
            scanf("%lld", &t);
            diff = INF, l = 0, r = 1;
            while (r <= n && diff) {
                tmp = sum[r].first - sum[l].first;
                if (abs(tmp - t) < diff) {
                    diff = abs(tmp - t);
                    ans = tmp;
                    st = sum[l].second;
                    en = sum[r].second;
                }
                if (tmp > t) l++;
                if (tmp < t) r++;
                if (l == r) r++;
            }
            if (st > en) swap(st, en);
            printf("%lld %d %d\n", ans, st + 1, en);
        }
    }

#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
