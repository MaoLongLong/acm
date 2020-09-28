#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1005;
int t, n, deadline, score, ans;
bool vis[maxn];

struct Subject {
    int deadline, score;
} sb[maxn];

bool cmp(Subject s1, Subject s2) {
    if (s1.score == s2.score) {
        return s1.deadline < s2.deadline;
    }
    return s1.score > s2.score;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &sb[i].deadline);
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d", &sb[i].score);
        }
        sort(sb, sb + n, cmp);
        ans = 0;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; ++i) {
            int j;
            for (j = sb[i].deadline; j > 0; --j) {
                if (!vis[j]) {
                    vis[j] = 1;
                    break;
                }
            }
            if (j == 0) {
                ans += sb[i].score;
            }
        }
        printf("%d\n", ans);
    }
    // system("pause");
    return 0;
}
