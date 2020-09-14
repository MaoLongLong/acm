#define LL long long

void ex_gcd(LL a, LL b, LL &x, LL &y) {
    if (!b) {
        x = 1, y = 0;
    } else {
        ex_gcd(b, a % b, y, x);
        y -= x * (a / b);
    }
}

LL mod_reverse(LL a, LL b) {
    LL x, y;
    ex_gcd(a, b, x, y);
    return (x + b) % b;
}

// =================================

LL quick_pow(int a, int n, int mod) {
    LL ans = 1;
    while (n) {
        if (n & 1) ans = ans * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ans;
}

LL mod_reverse_pow(int a, int p) {
    return quick_pow(a, p - 2, p);
}
