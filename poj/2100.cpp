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
using namespace std;
const int MAXN = 10000;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef unsigned long long ULL;

LL n, l, r, sum;
vector<pair<LL, LL>> ans;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

	scanf("%lld", &n);
	l = r = 1;
	sum = 0;
	while (1) {
		while (r * r <= n && sum < n) {
			sum += r * r;
			r++;
		}
		if (r * r > n && sum < n) break;
		if (sum == n) ans.push_back(make_pair(l, r));
		sum -= l * l;
		l++;
	}
	
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); ++i) {
		pair<int, int> p = ans[i];
		printf("%lld", p.second - p.first);
		for (int i = p.first; i < p.second; ++i) printf(" %lld", i);
		printf("\n");
	}
	
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
