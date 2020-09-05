// 快速幂
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
typedef unsigned long long ULL;

LL quick_pow(LL x, LL n) {
    LL res = 1;
    while (n) {
        if (n & 1) res = res * x % 10;
        x = x * x % 10;
        n >>= 1;
    }
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t;
    LL n;
    scanf("%d", &t);
    while (t--) {
        scanf("%lld", &n);
        printf("%lld\n", quick_pow(n, n));
    }

#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
