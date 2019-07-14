// 解方程(equation)
// author: kelvin
// status: AC
#include <cstdio>
#include <algorithm>
#include <cstring>
typedef long long int64;
const int P1 = 10007, P2 = 10009, P3 = 100000007;
char str[10007];
int x1[107], x2[107], x3[107];
int r1[P1], r2[P2], cnt1, cnt2, n, m;
int qmod(int x, int y, int p)
{
    int ans = 1;
    while (y)
    {
        if (y & 1)
            ans = 1LL * ans * x % p;
        x = 1LL * x * x % p;
        y >>= 1;
    }
    return ans;
}
//一个多项式模P的结果如果为0，就将解存入数组r
void polymod(int P, int co[], int r[], int &cnt)
{
    for (int i = 0; i < P; ++i)
    {
        int t = 0;
        for (int j = n; j >= 0; --j)
            t = (t * i + co[j]) % P;
        if (t == 0)
            r[cnt++] = i;
    }
}

void initX(char str[], int i)
{
    int len = strlen(str);
    x1[i] = x2[i] = x3[i] = 0;
    for (int j = str[0] == '-' ? 1 : 0; j < len; ++j)
    {
        x1[i] = (x1[i] * 10 % P1 + str[j] - '0') % P1;
        x2[i] = (x2[i] * 10 % P2 + str[j] - '0') % P2;
        x3[i] = (x3[i] * 10 % P3 + str[j] - '0') % P3;
    }
    if (str[0] == '-')
    {
        x1[i] = -x1[i];
        x2[i] = -x2[i];
        x3[i] = -x3[i];
    }
}

inline int CRT(int a, int b, int q1, int m1, int q2, int m2, int M)
{
    return (1LL * q2 * a % M * m1 % M + 1LL * q1 * b % M * m2 % M) % M;
}

int main()
{
    // freopen("equation.in", "r", stdin);
    // freopen("equation.out", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; ++i)
    {
        scanf("%s", str);
        initX(str, i);
    }
    polymod(P1, x1, r1, cnt1);
    polymod(P2, x2, r2, cnt2);
    int cnts = 0, PQ = P1 * P2;
    int ans[cnt1 * cnt2];
    int64 q1 = qmod(P1, P2 - 2, P2), q2 = qmod(P2, P1 - 2, P1);
    for (int i = 0; i < cnt1; i++)
        for (int j = 0; j < cnt2; j++)
        {
            int r = CRT(r1[i], r2[j], q1, P2, q2, P1, PQ);
            if (1 <= r && r <= m)
            {
                int t = 0;
                for (int k = n; k >= 0; k--)
                    t = (1LL * t * r % P3 + x3[k]) % P3;
                if (t == 0)
                    ans[cnts++] = r;
            }
        }
    std::sort(ans, ans + cnts);
    printf("%d\n", cnts);
    for (int i = 0; i < cnts; i++)
        printf("%d\n", ans[i]);
    return 0;
}