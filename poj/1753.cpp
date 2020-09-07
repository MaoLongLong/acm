/**
 * 状态压缩，bfs
 * 用16位二进制数 1111 1111 1111 1111 (0 ~ 65535) 表示棋盘状态
 * 1表示黑色，0表示白色。当对应的十进制数值为0时表示全白，65535表示全黑
 */
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
int a[16], dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
bool vis[MAXN + 5];

void init() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            int bit = 1 << (15 - (i * 4 + j));
            for (int k = 0; k < 4; ++k) {
                int ni = i + dir[k][0], nj = j + dir[k][1];
                if (ni >= 0 && nj >= 0 && ni < 4 && nj < 4) {
                    bit ^= (1 << (15 - (ni * 4 + nj)));
                }
            }
            a[i * 4 + j] = bit;
        }
    }
}

int bfs(int bit) {
    queue<P> que;
    que.push(make_pair(bit, 0));
    vis[bit] = 1;
    while (!que.empty()) {
        P p = que.front();
        que.pop();
        if (p.first == 0 || p.first == MAXN) return p.second;
        for (int i = 0; i < 16; ++i) {
            int next_state = p.first ^ a[i];
            if (!vis[next_state]) {
                que.push(make_pair(next_state, p.second + 1));
                vis[next_state] = 1;
            }
        }
    }
    return -1;
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
            if (c == 'b') bit ^= (1 << (15 - (i * 4 + j)));
        }
        getchar();  // 吃回车
    }

    init();
    mem(vis, 0);
    int ans = bfs(bit);
    if (ans == -1)
        printf("Impossible\n");
    else
        printf("%d\n", ans);

#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
