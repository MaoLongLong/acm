#include <bits/stdc++.h>
using namespace std;
const int maxn = 5005;
const int maxm = 400005;

int n, m, u, v, w, len = 0, cnt = 0, ans = 0, dis[maxn], head[maxn];
bool vis[maxn];

struct Edge {
    int v, w, next;
} e[maxm];

inline void add (int u, int v, int w) {
    e[++len].v = v;
    e[len].w = w;
    e[len].next = head[u];
    head[u] = len;
}

typedef pair<int, int> node;
priority_queue<node, vector<node>, greater<node> > q;
void prim() {
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    q.push(make_pair(0, 1));
    while (!q.empty() && cnt < n) {
        node t = q.top();
        q.pop();
        if (vis[t.second]) continue;
        vis[t.second] = 1;
        ++cnt;
        ans += t.first;
        for (int i = head[t.second]; i; i = e[i].next) {
            if (e[i].w < dis[e[i].v]) {
                dis[e[i].v] = e[i].w;
                q.push(make_pair(e[i].w, e[i].v));
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0;i < m; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
        add(v, u, w);
    }
    prim();
    printf("%d\n", ans);
    // system("pause");
    return 0;
}
