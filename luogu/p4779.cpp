#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int maxm = 2e5 + 5;

int n, m, s, u, v, w, len = 0, head[maxn], dis[maxn];
bool vis[maxn];

struct Edge {
    int u, v, w, next;
} e[maxm];

inline void add(int u, int v, int w) {
    e[++len].u = u;
    e[len].v = v;
    e[len].w = w;
    e[len].next = head[u];
    head[u] = len;
}

// queue<int> q;
// void spfa() {
//     memset(vis, 0, sizeof(vis));
//     memset(dis, 0x3f, sizeof(dis));
//     q.push(s);
//     vis[s] = 1;
//     dis[s] = 0;
//     while (!q.empty()) {
//         u = q.front();
//         q.pop();
//         vis[u] = 0;
//         for (int i = head[u]; i; i = e[i].next) {
//             v = e[i].v, w = e[i].w;
//             if (dis[u] + w < dis[v]) {
//                 dis[v] = dis[u] + w;
//                 if (!vis[v]) {
//                     q.push(v);
//                     vis[v] = 1;
//                 }
//             }
//         }
//     }
// }

typedef pair<int, int> node;
priority_queue<node, vector<node>, greater<node> > q;
void dijkstra() {
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    q.push(make_pair(0, s));
    while (!q.empty()) {
        node t = q.top();
        q.pop();
        u = t.second;
        if (vis[u]) continue;
        vis[u] = 1;
        for (int i = head[u]; i; i = e[i].next) {
            v = e[i].v, w = e[i].w;
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                q.push(make_pair(dis[v], v));
            }
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
    }
    // spfa();
    dijkstra();
    for (int i = 1; i <= n; ++i) printf("%d ", dis[i]);
    // system("pause");
    return 0;
}
