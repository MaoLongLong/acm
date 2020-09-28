// spfa,判断环路
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
#define ll long long
#define ull unsigned long long
using namespace std;

const int maxn = 105;

int n, m, s, u, v, len, cnt[maxn], vis[maxn], head[maxn];
double x, rate, com, dis[maxn];
queue<int> q;

struct Edge {
    int u, v, next;
    double rate, com;
} e[maxn << 1];

inline void add(int u, int v, double rate, double com) {
    e[++len].u = u;
    e[len].v = v;
    e[len].rate = rate;
    e[len].com = com;
    e[len].next = head[u];
    head[u] = len;
}

void spfa() {
    dis[s] = x;
    q.push(s);
    vis[s] = 1;
    while (!q.empty()) {
        u = q.front();
        q.pop();
        vis[u] = 0;
        for (int i = head[u]; i; i = e[i].next) {
            v = e[i].v, rate = e[i].rate, com = e[i].com;
            if ((dis[u] - com) * rate > dis[v]) {
                dis[v] = (dis[u] - com) * rate;
                cnt[v] = cnt[u] + 1;
                if (cnt[v] == n) {
                    printf("YES\n");
                    return;
                }
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
    printf("NO\n");
}

int main() {
    fill(vis, vis + maxn, 0);
    fill(dis, dis + maxn, 0);
    fill(cnt, cnt + maxn, 0);
    fill(head, head + maxn, 0);
    len = 0;
    scanf("%d%d%d%lf", &n, &m, &s, &x);
    for (int i = 0; i <m; ++i) {
        scanf("%d%d%lf%lf", &u, &v, &rate, &com);
        add(u, v, rate, com);
        scanf("%lf%lf", &rate, &com);
        add(v, u, rate, com);
    }
    spfa();
    // system("pause");
    return 0;
}
