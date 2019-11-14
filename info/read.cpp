/* 快读性能测试
结果：比scanf快约3倍 */
#include <cstdio>
#include <ctime>
const int SZ = 5e5;

void read(int &x) {
    x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
        ch = getchar();
    while (ch >= '0' && ch <= '9')
        x = x*10 + ch - '0', ch = getchar();
}

int main() {
    freopen("data.txt", "r", stdin);
    int t0 = clock();
    int tmp;
    for (register int i = 1; i <= SZ; i++)
        scanf("%d", &tmp);
    int t1 = clock() - t0;
    for (register int i = 1; i <= SZ; i++)
        read(tmp);
    int t2 = clock() - t1;
    printf("scanf: %dms\nread: %dms", t1, t2);
    return 0;
}

/* 5e5个10000000
scanf: 302ms
read: 113ms */