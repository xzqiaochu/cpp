//产生数
#include <cstdio>
char s[30];
int k, i, j, jj, f, ans[23] = {1}, c[15][2];
int main()
{
    scanf("%s%d", s, &k);
    for (; i < k; ++i)
        scanf("%d%d", &c[i][0], &c[i][1]);
    for (i = 0; s[i]; ++i)
    {
        f = 1 << s[i] - '0'; //这一位原来的数先标记上
        for (jj = 0; jj < 9; ++jj)
            for (j = 0; j < k; ++j)
                if (f & 1 << c[j][0])
                    f |= 1 << c[j][1]; //如果能达到规则左边的数，则标记右边的数也可达到
        for (jj = 0; f; ++jj, f &= f - 1)
            ; //计算f的二进制表示中1的个数
        //f&=f-1的作用是将f的二进制表示中最右边的1变为0
        if (jj > 1)
        {
            for (j = 0; j < 22; ++j)
                ans[j] *= jj;
            for (j = 0; j < 22; ++j)
                ans[j + 1] += ans[j] / 10, ans[j] %= 10;
        }
    }
    for (i = 22; !ans[i]; --i)
        ;
    while (putchar(ans[i] + '0'), --i >= 0)
        ;
    return 0;
}