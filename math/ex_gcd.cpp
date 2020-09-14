#define LL long long

LL ex_gcd(LL a, LL b, LL &x, LL &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    } else {
        int ret = ex_gcd(b, a % b, y, x);
        y -= x * (a / b);
        return ret;
    }
}
