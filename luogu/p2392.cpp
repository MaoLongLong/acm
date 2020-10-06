#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int s[4], a[25], ans = 0, l, r, res;

void dfs(int x, int s) {
    if (x == s) {
        res = min(res, max(l, r));
        return;
    }
    l += a[x];
    dfs(x + 1, s);
    l -= a[x];
    r += a[x];
    dfs(x + 1, s);
    r -= a[x];
}

int main() {
    for (int i = 0; i < 4; ++i) scanf("%d", s + i);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < s[i]; ++j) scanf("%d", a + j);
        res = 0x3f3f3f3f;
        dfs(0, s[i]);
        ans += res;
    }
    printf("%d\n", ans);
    // system("pause");
    return 0;
}
