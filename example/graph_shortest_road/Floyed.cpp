/* Floyed全局最短路
时间复杂度：O(n^3)
出处：MFOJ graph_shortest_road A
最后修改时间：2019-06-08 */

/* 例题出处：MFOJ graph_shortest_road A
最短路径问题(short)
描述
    平面上有n个点（n<=100），每个点的坐标均在-10000~10000之间。其中的一些点之间有连线。
    若有连线，则表示可从一个点到达另一个点，即两点间有通路，通路的距离为两点间的直线距离。
    现在的任务是找出从一点到另一点之间的最短路径。
输入
    输入共n+m+3行，其中:
    第一行为整数n。
    第2行到第n+1行（共n行） ，每行两个整数x和y，描述了一个点的坐标。
    第n+2行为一个整数m，表示图中连线的个数。
    此后的m行，每行描述一条连线，由两个整数i和j组成，表示第i个点和第j个点之间有连线。
    最后一行：两个整数s和t，分别表示源点和目标点。
输出
    输出仅一行，一个实数（保留两位小数），表示从s到t的最短路径长度。
输入样例 1 
5 
0 0
2 0
2 2
0 2
3 1
5
1 2
1 3
1 4
2 5
3 5
1 5
输出样例 1
3.41 */

#include <cstdio>
#include <cstring>
#include <cmath>

const int MAXN = 105;

int n, m, s, t, x[105], y[105];
double dis[MAXN][MAXN];

int main()
{
    memset(dis, 0x7f, sizeof(dis));
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", x + i, y + i);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        int from, to;
        scanf("%d%d", &from, &to);
        double d = sqrt(pow(x[from] - x[to], 2) + pow(y[from] - y[to], 2));
        dis[from][to] = d, dis[to][from] = d;
    }
    // Floyed全局最短路
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (k != i && k != j && i != j)
                    if (dis[i][j] > dis[i][k] + dis[k][j])
                        dis[i][j] = dis[i][k] + dis[k][j];
    scanf("%d%d", &s, &t);
    printf("%.2f", dis[s][t]);
    return 0;
}