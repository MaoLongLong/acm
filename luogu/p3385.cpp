#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define pi acos(-1.0)
#define maxn 6005
#define ll long long
#define ull unsigned long long
using namespace std;
int read() {
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
        x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
    return x * f;
}

struct Edge {
    int u, v, w, next;
} e[maxn];

int t, n, m, u, v, w, len, dis[maxn], head[maxn], cnt[maxn], vis[maxn];
queue<int> q;

inline void add(int u, int v, int w) {
    e[++len].u = u;
    e[len].v = v;
    e[len].w = w;
    e[len].next = head[u];
    head[u] = len;
}

void spfa() {
    dis[1] = 0;
    q.push(1);
    vis[1] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int i = head[u]; i; i = e[i].next) {
            int v = e[i].v, w = e[i].w;
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                cnt[v] = cnt[u] + 1;
                if (cnt[v] >= n) {
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
    t = read();
    while (t--) {
        // init
        len = 0;
        memset(dis, 0x3f, sizeof(dis));
        memset(head, 0, sizeof(head));
        memset(vis, 0, sizeof(vis));
        memset(cnt, 0, sizeof(cnt));
        while (!q.empty()) q.pop();

        n = read(), m = read();
        for (int i = 0; i < m; ++i) {
            u = read(), v = read(), w = read();
            add(u, v, w);
            if (w >= 0) add(v, u, w);
        }
        spfa();
    }
    // system("pause");
    return 0;
}
