// 二分查找
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
#define INF 0x3f3f3f3f
#define PI acos(-1.0)
#define MAXN 10005
#define LL long long
#define ULL unsigned long long
using namespace std;

int t, n, f, tmp;
double sum, l, r, mid, a[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &f);
        f++; // +1是因为自己也要吃
        sum = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%lf", a + i);
            a[i] = PI * a[i] * a[i];
            sum += a[i];
        }
        /**
         * 最差的情况是大家都分不到, 也就是0
         * 最好的情况是大家平分所有, 也就是sum / f
         * 从这里开始二分
         */
        l = 0, r = sum / f, mid = (l + r) / 2;
        // 达到一定精度结束循环, 1e-5就是 10 ^ (-5), 精度太高容易超时，太低容易WA
        while (r - l > 1e-5) {
            tmp = 0;
            // 计算按照mid这个量，每一块饼能分给几个人，求总和
            for (int i = 0; i < n; ++i) tmp += (int)(a[i] / mid);
            if (tmp >= f)
                l = mid;
            else
                r = mid;
            mid = (l + r) / 2;
        }
        printf("%.4lf\n", mid);
    }

#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
