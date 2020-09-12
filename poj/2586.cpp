// 贪心
#include <cstdio>

int main() {
    int s, d, ans;
    while (~scanf("%d%d", &s, &d)) {
        // 任意连续的5个月都是亏损, 枚举5个月内的所有可能，尽可能多选s (贪心)
        if (4 * s < d)
            ans = 10 * s - 2 * d;  // ssssdssssdss
        else if (3 * s < 2 * d)
            ans = 8 * s - 4 * d;  // sssddsssddss
        else if (2 * s < 3 * d)
            ans = 6 * s - 6 * d;  // ssdddssdddss
        else if (s < 4 * d)
            ans = 3 * s - 9 * d;  // sddddsddddsd
        else
            ans = -1;

        if (ans < 0)
            printf("Deficit\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}
