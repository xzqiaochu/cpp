// 多重背包 (http://www.mfstem.org/contest/25/problem/3)
// author: xzqiaochu
// status: AC
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1007, MAXV = 107;

int n, V, w[MAXN], c[MAXN], num[MAXN], f[MAXV];

void zeroOnePack(int cost, int val)
{
    for (int v = V; v >= cost; v--)
        f[v] = max(f[v], f[v - cost] + val);
}

void completePack(int cost, int val)
{
    for (int v = cost; v <= V; v++)
        f[v] = max(f[v], f[v - cost] + val);
}

void multiplePack(int cost, int val, int amount)
{
    if (cost * amount >= V)
    {
        completePack(cost, val);
        return;
    }
    for (int k = 1; k < amount; amount -= k, k *= 2)
        zeroOnePack(k * cost, k * val);
    zeroOnePack(amount * cost, amount * val);
}

int main()
{
    scanf("%d%d", &V, &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d%d", w + i, c + i, num + i);
    for (int i = 1; i <= n; i++)
    {
        if (num[i] == 1)
            zeroOnePack(w[i], c[i]);
        else if (num[i] == 0)
            completePack(w[i], c[i]);
        else
            multiplePack(w[i], c[i], num[i]);
    }
    printf("%d", f[V]);
    return 0;
}