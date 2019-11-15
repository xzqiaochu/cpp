/* CLOCKS_PER_SEC 常量
clcok() 一分钟增加的数量
可用于骗分 */
#include <cstdio>
#include <ctime>


int main() {
    time_t st = clock(); // time_t 实际上是 long long
    while (1) {
        if ((clock() - st) * 1000 / CLOCKS_PER_SEC > 1000)
            break;
    }
    time_t ed = clock();
    printf("%lld", ed - st);
    return 0;
}