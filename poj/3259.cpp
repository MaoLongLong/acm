// 负环, spfa
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

const int maxn = 505;
const int maxm = 2505;
const int maxw = 205;

int f, n, m, w, s, e, t, len, head[maxn], dis[maxn], cnt[maxn];
bool vis[maxn];
queue<int> q;

struct Edge {
    int s, e, t, next;
} edge[maxm * 2 + maxw];

inline void add(int s, int e, int t) {
    edge[++len].s = s;
    edge[len].e = e;
    edge[len].t = t;
    edge[len].next = head[s];
    head[s] = len;
}

void spfa() {
    dis[1] = 0;
    q.push(1);
    vis[1] = 1;
    while (!q.empty()) {
        s = q.front();
        q.pop();
        vis[s] = 0;
        for (int i = head[s]; i; i = edge[i].next) {
            e = edge[i].e, t = edge[i].t;
            if (dis[s] + t < dis[e]) {
                dis[e] = dis[s] + t;
                cnt[e] = cnt[s] + 1;
                if (cnt[e] == n) {
                    printf("YES\n");
                    return;
                }
                if (!vis[e]) {
                    q.push(e);
                    vis[e] = 1;
                }
            }
        }
    }
    printf("NO\n");
}

int main() {
    scanf("%d", &f);
    while (f--) {
        len = 0;
        memset(dis, 0x3f, sizeof(dis));
        memset(cnt, 0, sizeof(cnt));
        memset(vis, 0, sizeof(vis));
        memset(head, 0, sizeof(head));
        scanf("%d%d%d", &n, &m, &w);
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &s, &e, &t);
            add(s, e, t);
            add(e, s, t);
        }
        for (int i = 0; i < w; ++i) {
            scanf("%d%d%d", &s, &e, &t);
            add(s, e, -t);
        }
        spfa();
    }
    // system("pause");
    return 0;
}
