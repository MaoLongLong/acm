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
#define inf 0x3f3f3f3f
#define pi acos(-1.0)
#define maxn 100000005
#define ll long long
#define ull unsigned long long
using namespace std;
int read() {
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}

int n, q, k, prime[maxn];
bool vis[maxn];

void get_prime() {
    int cnt = 0;
    for (int i = 2; i <= n; ++i) {
        if (!vis[i]) prime[cnt++] = i;
        for (int j = 0; j < cnt && i * prime[j] <= n; ++j) {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

int main() {
    n = read(), q = read();
    get_prime();
    for (int i = 0; i < q; ++i) {
        k = read();
        printf("%d\n", prime[k - 1]);
    }
    // system("pause");
    return 0;
}
