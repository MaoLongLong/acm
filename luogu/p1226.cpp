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
#define mem(a, v) memset(a, v, sizeof(a))
#define inf 0x3f3f3f3f
#define pi acos(-1.0)
#define maxn 100005
#define ll long long
#define ull unsigned long long
using namespace std;

ll quick_pow(ll b, ll p, ll k) {
    ll ans = 1;
    while (p) {
        if (p & 1) ans = ans * b % k;
        b = b * b % k;
        p >>= 1;
    }
    return ans % k;
}

int main() {
    ll b, p, k;
    scanf("%lld%lld%lld", &b, &p, &k);
    printf("%lld^%lld mod %lld=%lld\n", b, p, k, quick_pow(b, p, k));
    system("pause");
    return 0;
}
