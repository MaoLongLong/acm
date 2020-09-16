#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define pi acos(-1.0)
#define maxn 1000005
#define ll long long
#define ull unsigned long long
#define re register
#define il inline
using namespace std;

char s1[maxn], s2[maxn];
int n, m, kmp[maxn];

void get_next() {
    int i = 0, j = -1;
    kmp[0] = -1;
    while (i < m) {
        if (j == -1 || s2[i] == s2[j])
            kmp[++i] = ++j;
        else
            j = kmp[j];
    }
}

int main() {
    scanf("%s%s", s1, s2);
    n = strlen(s1);
    m = strlen(s2);
    get_next();
    int i = 0, j = 0;
    while (i < n) {
        if (j == -1 || s1[i] == s2[j])
            ++i, ++j;
        else
            j = kmp[j];
        if (j == m) {
            printf("%d\n", i - m + 1);
            j = kmp[m];
        }
    }
    for (int i = 1; i <= m; ++i) printf("%d ", kmp[i]);
    // system("pause");
    return 0;
}
