#include <cstdio>

int main() {
    double c, sum;
    int n;
    while (scanf("%lf", &c)) {
        if (c < 0.01 || c > 5.20) break;
        sum = 0, n = 2;
        while (sum < c) {
            sum += 1.0 / n;
            ++n;
        }
        printf("%d card(s)\n", n - 2);
    }
    return 0;
}
