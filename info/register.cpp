/* register优化测试
结果：register会快很多，但对于小数据(1e6以内)两者都非常快 */
#include <cstdio>
#include <ctime>
const int SZ = 1e7;

int main() {
    int t0 = clock();
    for (register int i = 0; i <= SZ; i++);
    int t1 = clock() - t0;
    for (int i = 0; i <= SZ; i++);
    int t2 = clock() - t1;
    printf("register: %dms | none: %dms", t1, t2);
    return 0;
}

/* (1000us = 1ms)
1e3：register: 0us | none: 356us
1e4：register: 3us | none: 366us
1e5：register: 25us | none: 571us
1e6：register: 270us | none: 2010us
1e7：register: 1ms | none: 15ms
1e8：register: 26ms | none: 143ms 
1e9：register: 263ms | none: 1416ms */