/* Dijkstra（堆优化）单源最短路
时间复杂度：O(m log n)
出处：算法竞赛-图论-最短路 0x61 P347
最后修改时间：2019-06-27 */

/* 例题出处：MFOJ graph_shortest_road K
最短路(spfa)
描述
    给定M条边，N个点的带权无向图。求1到N的最短路。
输入
    第一行：N,M(N≤100000，M≤500000)
    接下来M行3个正整数：ai,bi,ci表示ai,bi之间有一条长度为ci的路，ci≤1000。
输出
    一个整数，表示1到N的最短距离。
输入样例 1 
4 4
1 2 1
2 3 1
3 4 1
2 4 1
输出样例 1
2
提示
    注意图中可能有重边和自环，数据保证1到N有路径相连。 */

#include <cstdio>
#include <iostream>
#include <utility>
#include <queue>

#define next Next

using namespace std;

const int MAXN = 1e5 + 7, MAXM = (5e5 + 7) * 2, INF = 0x3f3f3f3f;

int n, m;
int tot, head[MAXN], edge[MAXM], to[MAXM], next[MAXM];
int d[MAXN];
bool v[MAXN];
priority_queue< pair<int, int> > q;

inline void add(int x, int y, int z)
{
    edge[++tot] = z, to[tot] = y;
    next[tot] = head[x], head[x] = tot;
}

// Dijkstra（堆优化）
bool dijkstra()
{
    for (int i = 1; i <= n; i++)
        d[i] = INF;
    d[1] = 0;
    q.push(make_pair(0, 1)); // 第一维 距离（相反数），第二维 编号
    while (!q.empty())
    {
        int x = q.top().second;
        q.pop();
        if (v[x])
            continue;
        v[x] = true; // 标记节点x已被用过
        if (x == n)
            return true;
        for (int i = head[x]; i; i = next[i])
        {
            int y = to[i], z = edge[i];
            if (d[x] + z < d[y])
            {
                d[y] = d[x] + z;
                q.push(make_pair(-d[y], y));
            }
        }
    }
    return false;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z);
        add(y, x, z);
    }
    if (dijkstra())
        printf("%d", d[n]);
    else
        printf("%d", -1);
    return 0;
}