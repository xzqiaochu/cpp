/* 0/1背包
时间复杂度：O(nm)
空间复杂度：O(m)
出处：背包问题汇总.pptx
最后修改时间：2019-07-03 */

/* 例题出处：背包问题汇总.pptx
0/1背包(package)
【问题描述】
    一个旅行者有一个最多能用m公斤的背包，现在有n件物品，它们的重量分别是W1，W2，...,Wn,它们的价值分别为C1,C2,...,Cn.若每种物品只有一件求旅行者能获得最大总价值。 
【输入格式】
    第一行：两个整数，M(背包容量，M<=200)和N(物品数量，N<=30)；
    第2..N+1行：每行二个整数Wi,Ci，表示每个物品的重量和价值。
【输出格式】
    仅一行，一个数，表示最大总价值。
【样例输入】package.in
 10 4
 2  1
 3  3
 4  5
 7  9
【样例输出】package.out
 12 */

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
        for (int j = m; j >= w[i]; j--)
            f[j] = std::max(f[j], f[j - w[i]] + c[i]);
    printf("%d", f[m]);
    return 0;
}