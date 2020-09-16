#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#define inf 0x3f3f3f3f
#define pi acos(-1.0)
#define maxn 10005
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

int main() {
    system("pause");
    return 0;
}
