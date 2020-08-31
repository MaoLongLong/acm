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
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t, n, s, x, l, r, sum, ans;
    vector<int> v = vector<int>();
    cin >> t;
    while (t--) {
        cin >> n >> s;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            v.push_back(x);
        }
        l = r = sum = 0;
        ans = INF;
        while (1) {
            while (r < n && sum < s) sum += v[r++];
            if (sum < s) break;
            ans = min(ans, r - l);
            sum -= v[l++];
        }
        if (ans == INF) ans = 0;
        cout << ans << endl;
        v.clear();
    }
    return 0;
}
