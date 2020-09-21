#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define pi acos(-1.0)
#define maxn 1000005
#define maxm 10005
#define ll long long
#define ull unsigned long long
#define re register
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

int n, op, x, heap[maxn], heap_size;

void swim(int x) {
    int p = x >> 1;
    while (p > 0 && heap[x] < heap[p]) {
        swap(heap[x], heap[p]);
        x = p;
        p = x >> 1;
    }
}

void sink(int x) {
    int c = x << 1;
    while (c <= heap_size) {
        if (c + 1 <= heap_size && heap[c + 1] < heap[c]) c++;
        if (heap[c] < heap[x]) {
            swap(heap[c], heap[x]);
            x = c;
            c = x << 1;
        } else {
            break;
        }
    }
}

void pop() {
    swap(heap[1], heap[heap_size--]);
    sink(1);
}

int main() {
    n = read();
    while (n--) {
        op = read();
        if (op == 1) {
            x = read();
            heap[++heap_size] = x;
            swim(heap_size);
        } else if (op == 2) {
            printf("%d\n", heap[1]);
        } else {
            pop();
        }
    }
    // system("pause");
    return 0;
}
