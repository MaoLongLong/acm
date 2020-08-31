// 尺取法
#include <algorithm>
#include <bitset>
#include <climits>
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
#define INF 0x3f3f3f3f
#define MAX 1000005
using namespace std;
typedef long long LL;

int p, n, l, r, sum, ans, a[MAX];
set<int> vis;
map<int, int> cnt;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &p);
    for (int i = 0; i < p; ++i) {
        scanf("%d", a + i);
        vis.insert(a[i]);
    }
    n = vis.size();
    l = r = sum = 0;
    ans = INF;
    while (1) {
        while (r < p && sum < n)
            if (cnt[a[r++]]++ == 0) sum++;
        if (sum < n) break;
        ans = min(ans, r - l);
        if (--cnt[a[l++]] == 0) sum--;
    }
    printf("%d\n", ans);
    return 0;
}
