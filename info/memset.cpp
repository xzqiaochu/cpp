/* 数组清空：memset PK for循环
结果：for循环用register优化，比memset快3倍！
若不优化，则比memset稍慢一些
如果要多次初始化数组的话，建议使用for循环 */
#include <cstdio>
#include <cstring>
#include <ctime>
const int SZ = 1e8;

int a[SZ];

int main() {
    int t0 = clock();
    memset(a, 0, sizeof(a));
    int t1 = clock() - t0;
    for (register int i = 0; i < SZ; i++)
        a[i] = 0;
    int t2 = clock() - t1;
    printf("memset: %dms\nfor: %dms", t1, t2);
    return 0;
}

/* 1e8
memset: 154ms
for: 56ms */