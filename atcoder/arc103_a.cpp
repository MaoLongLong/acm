#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 100005;
inline int rd() {
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}

int n, x, l1, l2, cnt[2][maxn];
struct Pair {
	int id, cnt;
	Pair(int ID=0, int CNT=0): id(ID), cnt(CNT) {}
	bool operator<(const Pair &p) const {
		return cnt > p.cnt;
	}
} a[maxn], b[maxn];

int main() {
	n = rd();
	for (int i = 0; i < n; ++i) {
		x = rd();
		++cnt[i & 1][x];
	}
	for (int i = 1; i < maxn; ++i) {
		a[++l1] = Pair(i, cnt[0][i]);
		b[++l2] = Pair(i, cnt[1][i]);
	}
	sort(a + 1, a + maxn);
	sort(b + 1, b + maxn);
	if (a[1].id == b[1].id) {
		printf("%d\n", n - max(a[1].cnt + b[2].cnt, a[2].cnt + b[1].cnt));
	} else {
		printf("%d\n", n - a[1].cnt - b[1].cnt);
	}
	return 0;
}
