#define LL long long

LL quick_pow(int a, int n, int mod) {
    LL ans = 1;
    while (n) {
        if (n & 1) ans = ans * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ans;
}
