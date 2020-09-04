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
#define MAXN 100005
#define LL long long
#define ULL unsigned long long
using namespace std;

vector<int> v;
LL len;
int k, n, low, high, mid, ans;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    v.push_back(0);
    len = 1;
    // 记录拼接后的字符串依次多长, 方便查找位置 n 是属于哪个字符串
    while (v.back() + len<= INT_MAX) {
        v.push_back(v.back() + len++);
    }
    len--;

    scanf("%d", &k);
    while (k--) {
        scanf("%d", &n);
        low = 0, high = len;
        /**
         * 二分查找
         *    当 v[mid] < n && v[mid + 1] >= n 时
         *    可以确定, 待查找的字母在 v[mid + 1] 的范围里
         */
        while (low <= high) {
            mid = (low + high) >> 1;
            if (v[mid + 1] < n)
                low = mid + 1;
            else if (v[mid] >= n)
                high = mid - 1;
            else
                break;
        }
        ans = (n - v[mid]) % 9;
        printf("%d\n", ans ? ans : 9);
    }

#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
