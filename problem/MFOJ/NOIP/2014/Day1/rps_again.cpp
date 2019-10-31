// 生活大爆炸版石头剪刀布(rps) (http://www.mfstem.org/contest/18/problem/A)
// author: xzqiaochu
// status: AC
#include <cstdio>

const int SZ = 207;
// 0甲赢，1甲输，2平局
const char pk[5][6] =
{
    "21001",
    "02101",
    "10210",
    "11020",
    "00112"
};

int n, na, nb, a[SZ], b[SZ];
int cnta, cntb;

int main()
{
    // freopen("rps.in", "r", stdin);
    // freopen("rps.out", "w", stdout);
    scanf("%d%d%d", &n, &na, &nb);
    for (int i = 0; i < na; i++)
        scanf("%d", a + i);
    for (int i = 0; i < nb; i++)
        scanf("%d", b + i);
    for (int i = 0; i < n; i++)
    {
        if (pk[a[i % na]][b[i % nb]] == '0')
            cnta++;
        else if (pk[a[i % na]][b[i % nb]] == '1')
            cntb++;
    }
    printf("%d %d", cnta, cntb);
    return 0;
}