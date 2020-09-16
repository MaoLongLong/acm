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
#define maxn 10005
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

int n, m, z, x, y, a[maxn];

int find(int x) {
    return x == a[x] ? x : a[x] = find(a[x]);
}

void join(int x, int y) {
    int f1 = find(x), f2 = find(y);
    if (f1 != f2) {
        a[f1] = f2;
    }
}

int main() {
    n = read(), m = read();
    for (int i = 1; i <= n; ++i) a[i] = i;
    for (int i = 0; i < m; ++i) {
        z = read(), x = read(), y = read();
        if (z == 1)
            join(x, y);
        else {
            if (find(x) == find(y))
                printf("Y\n");
            else
                printf("N\n");
        }
    }
    system("pause");
    return 0;
}
