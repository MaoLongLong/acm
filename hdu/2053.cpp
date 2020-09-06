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

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n, m, flag;
    while (~scanf("%d", &n)) {
        m = n >> 1, flag = 1;  // 外加n本身还能整除一次
        for (int i = 1; i <= m; ++i) {
            if (n % i == 0) {
                ++flag;
            }
        }
        printf("%d\n", flag & 1);
    }

#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
