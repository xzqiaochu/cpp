/* 完全背包
时间复杂度：O(nm)
空间复杂度：O(m)
出处：背包问题汇总.pptx
最后修改时间：2019-07-04 */

/* 例题出处：背包问题汇总.pptx
完全背包问题
【问题描述】
    设有n种物品，每种物品有一个重量及一个价值。但每种物品的数量是无限的，同时有一个背包，最大载重量为M，今从n种物品中选取若干件(同一种物品可以多次选取)，使其重量的和小于等于M，而价值的和为最大。
【输入格式】
    第一行：两个整数，M(背包容量，M<=200)和N(物品数量，N<=30)；
    第2..N+1行：每行二个整数Wi,Ci，表示每个物品的重量和价值。
【输出格式】
    仅一行，一个数，表示最大总价值。
【样例输入】knapsack.in
    10  4
    2  1
    3  3
    4  5
    7  9
【样例输出】knapsack.out
　  max=12 */

#include <cstdio>
#include <algorithm>

const int MAXN = 37, MAXM = 207;

int n, m, w[MAXN], c[MAXN], f[MAXM];

int main()
{
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", w + i, c + i);
    for (int i = 1; i <= n; i++)
        for (int j = w[i]; j <= m; j++)
            f[j] = std::max(f[j], f[j - w[i]] + c[i]);
    printf("max=%d", f[m]);
    return 0;
}