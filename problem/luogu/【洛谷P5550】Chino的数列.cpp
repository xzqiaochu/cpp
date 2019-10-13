// 洛谷P5550
// author: xzqiaochu
// status: AC
// time: 2019/10/13
#include <cstdio>
#include <algorithm>

typedef long long int64;

const int SZ = 87;

int n, s, m;
int64 k;
int64 a[SZ];
int64 ori[SZ];

void save()
{
    for (int i = 1; i <= n; i++)
        ori[i] = a[i];
}

void go()
{
    std::swap(a[s], a[m]);
    int64 temp = a[1];
    for (int i = 1; i <= n - 1; i++)
        a[i] = a[i + 1];
    a[n] = temp;
}

bool check()
{
    for (int i = 1; i <= n; i++)
        if (a[i] != ori[i])
            return false;
    return true;
}

void calc()
{
    int64 t = n;
    save();
    for (int64 i = 1; i <= k; i++)
    {
        go();
        if (check())
        {
            t = i;
            break;
        }
    }
    int64 rst = k % t;
    for (int64 i = 1; i <= rst; i++)
        go();
    for (int i = 1; i <= n; i++)
        printf("%lld ", a[i]);
}

int main()
{
    scanf("%d%d%d%lld", &n, &s, &m, &k);
    for (int i = 1; i <= n; i++)
        scanf("%lld", a + i);
    calc();
    return 0;
}
