#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 105;
const int mod = 1e9 + 7;
inline ll read() {
    ll x = 0;
    int f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
        x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
    return x * f;
}

int n;
ll k;

struct Matrix {
    ll d[maxn][maxn];
    Matrix() { memset(d, 0, sizeof(d)); }
} a, ans;

Matrix operator*(const Matrix &m1, const Matrix &m2) {
    Matrix t;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                t.d[i][j] = (t.d[i][j] + m1.d[i][k] * m2.d[k][j] % mod) % mod;
    return t;
}

int main() {
    n = read(), k = read();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) a.d[i][j] = read();
    for (int i = 0; i < n; ++i) ans.d[i][i] = 1;
    while (k) {
        if (k & 1) ans = ans * a;
        a = a * a;
        k >>= 1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", ans.d[i][j]);
        }
        putchar('\n');
    }
    // system("pause");
    return 0;
}
