#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define pi acos(-1.0)
#define maxn 10005
#define ll long long
#define ull unsigned long long
#define re register
#define il inline
using namespace std;
int read() {
    int x = 0, f = 1;
    char c = getchar();
    while (!isdigit(c)) {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    return x * f;
}

int main() {
    int n, x;
    n = read();
    for (int i = n; i >= 0; --i) {
        x = read();
        if (x) {
            if (i != n && x > 0) printf("+");
            if (abs(x) > 1 || i == 0) printf("%d", x);
            if (x == -1 && i) printf("-");
            if (i > 1) printf("x^%d", i);
            if (i == 1) printf("x");
        }
    }
    // system("pause");
    return 0;
}
