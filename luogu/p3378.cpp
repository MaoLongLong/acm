#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define pi acos(-1.0)
#define maxn 1000005
#define maxm 10005
#define ll long long
#define ull unsigned long long
#define re register
#define il inline
using namespace std;
il int read() {
    re int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
        x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
    return x * f;
}

int n, op, x, a[maxn], heap_size;

il void swim(int x) {
    int p = x >> 1;
    while (p > 0 && a[x] < a[p]) {
        swap(a[x], a[p]);
        x = p;
        p = x >> 1;
    }
}

il void sink(int x) {
    int c = x << 1;
    while (c <= heap_size) {
        if (c + 1 <= heap_size && a[c + 1] < a[c]) c++;
        if (a[c] < a[x]) {
            swap(a[c], a[x]);
            x = c;
            c = x << 1;
        } else {
            break;
        }
    }
}

il void pop() {
    swap(a[1], a[heap_size--]);
    sink(1);
}

int main() {
    n = read();
    while (n--) {
        op = read();
        if (op == 1) {
            x = read();
            a[++heap_size] = x;
            swim(heap_size);
        } else if (op == 2) {
            printf("%d\n", a[1]);
        } else {
            pop();
        }
    }
    // system("pause");
    return 0;
}
