#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define pi acos(-1.0)
#define maxn 100005
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

void qsort(int a[], int l, int r) {
    if (l < r) {
        int mid = (l + r) >> 1;
        int pivot = a[mid];
        swap(a[l], a[mid]);
        int i = l, j = r;
        while (i < j) {
            while (i < j && a[j] >= pivot) --j;
            a[i] = a[j];
            while (i < j && a[i] < pivot) ++i;
            a[j] = a[i];
        }
        a[i] = pivot;
        qsort(a, l, i);
        qsort(a, i + 1, r);
    }
}

int main() {
    int a[maxn], n = read();
    for (re int i = 0; i < n; ++i) a[i] = read();
    qsort(a, 0, n - 1);
    printf("%d", a[0]);
    for (re int i = 1; i < n; ++i) printf(" %d", a[i]);
    // system("pause");
    return 0;
}
