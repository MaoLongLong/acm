// 贪心, 把圆问题转换成, 圆和坐标轴交点组成的线段问题
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

int n, d, d2, x, y, _case, ans;
bool flag;
vector<pair<double, double>> v;

int solve() {
    int cnt = 1;
    sort(v.begin(), v.end());
    double r = v[0].second;
    for (int i = 1; i < v.size(); ++i) {
        if (r < v[i].first) {
            ++cnt;
            r = v[i].second;
        } else if (v[i].second < r) {
            r = v[i].second;
        }
    }
    return cnt;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    _case = 1;
    while (scanf("%d%d", &n, &d) && (n || d)) {
        flag = 0, d2 = d * d;
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &x, &y);
            if (y > d) flag = 1;
            double offset = sqrt((double)(d2 - y * y));
            v.push_back(make_pair(x - offset, x + offset));
        }
        if (flag)
            ans = -1;
        else
            ans = solve();
        printf("Case %d: %d\n", _case++, ans);
        v.clear();
    }

#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
