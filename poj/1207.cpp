#include <algorithm>
#include <cstdio>
using namespace std;

int solve(int i) {
    int cnt = 1;
    while (i != 1) {
        if (i & 1)
            i = 3 * i + 1;
        else
            i >>= 1;
        ++cnt;
    }
    return cnt;
}

int main() {
    int a, b, x, y, ans;
    while (~scanf("%d%d", &a, &b)) {
        x = min(a, b);
        y = max(a, b);
        ans = 0;
        for (int i = x; i <= y; ++i) {
            ans = max(ans, solve(i));
        }
        printf("%d %d %d\n", a, b, ans);
    }
    return 0;
}
