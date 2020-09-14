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
#define maxm 500005
#define ll long long
#define ull unsigned long long
#define node pair<int, int>
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

struct edge {
    int u, v, w, next;
} e[maxm];

int n, m, s, u, v, w, cnt, dis[maxn], head[maxn];
bool vis[maxn];
priority_queue< node, vector<node>, greater<node> > q;

inline void add(int u, int v, int w) {
    e[++cnt].u = u;
    e[cnt].v = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void dijkstra() {
    fill(dis, dis + maxn, INT_MAX);
    dis[s] = 0;
    q.push(make_pair(0, s));
    while (!q.empty()) {
        node t = q.top();
        q.pop();
        int u = t.second;
        if (vis[u]) continue;
        vis[u] = 1;
        for (int i = head[u]; i; i = e[i].next) {
            int v = e[i].v, w = e[i].w;
            // 判断从起点经过u到达v是否会小于当前dis[v]
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                q.push(make_pair(dis[v], v));
            }
        }
    }
}

int main() {
    n = read(), m = read(), s = read();
    for (int i = 0; i < m; ++i) {
        u = read(), v = read(), w = read();
        add(u, v, w);
    }
    dijkstra();
    for (int i = 1; i <= n; ++i) printf("%d ", dis[i]);
    // system("pause");
    return 0;
}
