#include <cmath>
#include <cstdio>
const double pi = acos(-1.0);

int main() {
    int n, year;
    double x, y;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lf%lf", &x, &y);
        year = pi * (x * x + y * y) / 100;
        printf("Property %d: This property will begin eroding in year %d.\n", i, year + 1);
    }
    printf("END OF OUTPUT.\n");
    system("pause");
    return 0;
}
