// 欧拉筛法, 尺取法
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

int len, x, l, r, sum, cnt, prime[MAXN];
bool vis[MAXN];

void get_prime() {
	len = 0;
	memset(vis, 0, sizeof(vis));
	for (int i = 2; i <= MAXN; ++i) {
		if (!vis[i]) prime[len++] = i;
		for (int j = 0; j < len && i * prime[j] <= MAXN; ++j) {
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0) break;
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

	get_prime();
	while (scanf("%d", &x) && x) {
		l = r = sum = cnt = 0;
		while (1) {
			while (prime[r] <= x && sum < x) sum += prime[r++];
			if (sum < x && prime[r] > x) break;
			if (sum == x) cnt++;
			if (sum >= x) sum -= prime[l++];
		}
		printf("%d\n", cnt);
	}
	
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
