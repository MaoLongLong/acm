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
#define maxn 200005
#define ll long long
#define ull unsigned long long
#define lowbit(x) ((x) & (-x))
#define mid int m = (l + r) >> 1
#define lson rt << 1, l, m
#define rson rt << 1 | 1, m + 1, r
using namespace std;
int rd() {
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
    return x * f;
}

int h, w, n, wi, tree[maxn << 2];

void build(int rt, int l, int r) {
    if (l == r) {
        tree[rt] = w;
        return;
    }
    mid;
    build(lson);
    build(rson);
    tree[rt] = max(tree[rt << 1], tree[rt << 1 | 1]);
}

int query(int rt, int l, int r, int w) {
    if (l == r) {
        tree[rt] -= w;
        return l;
    }
    mid;
    int ans = -1;
    if (tree[rt << 1] >= w)
        ans = query(lson, w);
    else if (tree[rt << 1 | 1] >= w)
        ans = query(rson, w);
    tree[rt] = max(tree[rt << 1], tree[rt << 1 | 1]);
    return ans;
}

int main() {
    // for (int _case = 1; _case <= 6; ++_case) {
    //     freopen((to_string(_case) + ".in").c_str(), "r", stdin);
    //     freopen((to_string(_case) + ".out").c_str(), "w", stdout);
        while (~scanf("%d%d%d", &h, &w, &n)) {
            if (h > n) h = n;
            build(1, 1, h);
            for (int i = 1; i <= n; ++i) {
                scanf("%d", &wi);
                if (tree[1] < wi)
                    printf("-1\n");
                else
                    printf("%d\n", query(1, 1, h, wi));
            }
        }
    //     fclose(stdin);
    //     fclose(stdout);
    // }
    // system("pause");
    return 0;
}
