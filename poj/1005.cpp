#include <cmath>
#include <cstdio>
#define PI acos(-1.0)

int main() {
    int n, year;
    double x, y;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lf%lf", &x, &y);
        year = PI * (x * x + y * y) / 100;
        ++year;
        printf("Property %d: This property will begin eroding in year %d.\n", i,
               year);
    }
    printf("END OF OUTPUT.\n");
    return 0;
}
