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
#define MAXN 45
#define MAX2N 85
#define LL long long
#define ULL unsigned long long
using namespace std;

char a[MAXN], b[MAXN];
int n, m, an[MAXN], bn[MAXN], res[MAX2N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%s", a);
    scanf("%s", b);
    mem(an, 0);
    mem(bn, 0);
    mem(res, 0);
    n = strlen(a), m = strlen(b);
    for (int i = 0; i < n; ++i) an[i] = a[n - 1 - i] - '0';
    for (int i = 0; i < m; ++i) bn[i] = b[m - 1 - i] - '0';

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            res[i + j] += an[i] * bn[j];

    for (int i = 0; i < MAX2N; ++i) {
        if (res[i] >= 10) {
            res[i + 1] += res[i] / 10;
            res[i] %= 10;
        }
    }
    bool flag = 0;
    for (int i = MAX2N - 1; i >= 0; --i) {
        if (res[i]) flag = 1;
        if (flag) printf("%d", res[i]);
    }
    if (!flag) printf("0");

#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
