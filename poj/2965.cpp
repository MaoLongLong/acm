// 状态压缩, dfs
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
#define MAXN 65535
#define LL long long
#define ULL unsigned long long
#define P pair<int, int>
using namespace std;

char c;
int len = INF, a[16];
int cnt = 0;

vector<P> tmp, ans;

void init() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            int bit = 0;
            for (int k = 0; k < 4; ++k) {
                bit += (1 << (15 - (i * 4 + k)));
                bit += (1 << (15 - (k * 4 + j)));
            }
            a[i * 4 + j] = bit - (1 << (15 - (i * 4 + j)));
        }
    }
}

void dfs(int state, int cur) {
    if (state == 0) {
        if (tmp.size() < len) {
            len = tmp.size();
            ans.resize(len);
            copy(tmp.begin(), tmp.end(), ans.begin());
        }
        return;
    }
    if (cur > 15) return;
    dfs(state, cur + 1);
    tmp.push_back(make_pair(cur / 4 + 1, cur % 4 + 1));
    dfs(state ^ a[cur], cur + 1);
    tmp.pop_back(); // 回溯
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int bit = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            scanf("%c", &c);
            if (c == '+') bit ^= (1 << (15 - (i * 4 + j)));
        }
        getchar();
    }

    init();
    dfs(bit, 0);
    printf("%d\n", len);
    for (int i = 0; i < len; ++i)
        printf("%d %d\n", ans[i].first, ans[i].second);

#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
