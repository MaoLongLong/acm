// 字符串hash
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 10000000;

int n, m, len, x, cnt[maxn], ans[maxn];
bool flag, vis[maxn];
char c, tel[maxn];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    flag = 0, len = 0;
    memset(vis, 0, sizeof(vis));
    memset(cnt, 0, sizeof(cnt));
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", tel);
        m = strlen(tel), x = 0;
        for (int i = 0; i < m; ++i) {
            c = tel[i];
            if (c == '-' || c == 'Q' || c == 'Z') continue;
            x *= 10;
            if (c >= '0' && c <= '9')
                x += c - '0';
            else if (c == 'A' || c == 'B' || c == 'C')
                x += 2;
            else if (c == 'D' || c == 'E' || c == 'F')
                x += 3;
            else if (c == 'G' || c == 'H' || c == 'I')
                x += 4;
            else if (c == 'J' || c == 'K' || c == 'L')
                x += 5;
            else if (c == 'M' || c == 'N' || c == 'O')
                x += 6;
            else if (c == 'P' || c == 'R' || c == 'S')
                x += 7;
            else if (c == 'T' || c == 'U' || c == 'V')
                x += 8;
            else if (c == 'W' || c == 'X' || c == 'Y')
                x += 9;
        }
        ++cnt[x];
        if (!vis[x] && cnt[x] > 1) {
            flag = 1;
            vis[x] = 1;
            ans[len++] = x;
        }
    }
    if (!flag) {
        printf("No duplicates.\n");
    } else {
        sort(ans, ans + len);
        for (int i = 0; i < len; ++i) {
            printf("%03d-%04d %d\n", ans[i] / 10000, ans[i] % 10000, cnt[ans[i]]);
        }
    }
    // system("pause");
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}
