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
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#define mem(a, v) memset(a, v, sizeof(a))
#define INF 0x3f3f3f3f
#define PI acos(-1.0)
#define MAXN 100005
#define LL long long
#define ULL unsigned long long
using namespace std;

int n, m, a[MAXN];

bool check(int x) {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cnt += upper_bound(a + i, a + n, a[i] + x) - (a + i) - 1;
    }
    return cnt >= m;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) scanf("%d", a + i);
        sort(a, a + n);
        int tmp = n * (n - 1) / 2;
        if (tmp % 2)
            m = tmp / 2 + 1;
        else
            m = tmp / 2;
        int l = 0, r = INF;
        while (l < r) {
            int mid = (l + r) / 2;
            if (check(mid))
                r = mid;
            else
                l = mid + 1;
        }
        printf("%d\n", r);
    }

#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
