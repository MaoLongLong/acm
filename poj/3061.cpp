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
const int MAXN = 1000005;
const int INF = 0x3f3f3f3f;
typedef long long LL;

int t, n, s, x, l, r, sum, ans, a[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &s);
        for (int i = 0; i < n; ++i) scanf("%d", a + i);
        l = r = sum = 0;
        ans = INF;
        while (1) {
            while (r < n && sum < s) sum += a[r++];
            if (sum < s) break;
            ans = min(ans, r - l);
            sum -= a[l++];
        }
        if (ans == INF) ans = 0;
        printf("%d\n", ans);
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
