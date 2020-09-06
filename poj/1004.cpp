#include <cstdio>

int main() {
    double n, sum = 0;
    for (int i = 0; i < 12; ++i) {
        scanf("%lf", &n);
        sum += n;
    }
    printf("$%.2lf", sum / 12);
    return 0;
}
