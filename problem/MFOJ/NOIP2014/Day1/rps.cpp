// 大爆炸版石头剪刀布(rps) (http://www.mfstem.org/contest/18/problem/A)
// author: xzqiaochu
// status: AC
#include <cstdio>

const int MAXN = 207;
const char p[5][6] = 
{
    "01221",
    "20121",
    "12012",
    "11202",
    "22110"
};

int n, na, nb, ansa, ansb, a[MAXN], b[MAXN];

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
        char rst = p[a[i % na]][b[i % nb]];
        if (rst == '1')
            ansb++;
        else if (rst == '2')
            ansa++;
    }
    printf("%d %d", ansa, ansb);
    return 0;
}