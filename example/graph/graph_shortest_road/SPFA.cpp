/* SPFA(Shortest Path Fast Algorithm)单源最短路
时间复杂度：O(km) （k是一个较小的常数，平均值为2）
出处：算法竞赛-图论-最短路 0x61 P348
最后修改时间：2019-06-27 */

/* 例题出处：MFOJ graph_shortest_road E
信使(msner)
描述
    战争时期，前线有n个哨所，每个哨所可能会与其他若干个哨所之间有通信联系。信使负责在哨所之间传递信息，当然，这是要花费一定时间的（以天为单位）。指挥部设在第一个哨所。当指挥部下达一个命令后，指挥部就派出若干个信使向与指挥部相连的哨所送信。当一个哨所接到信后，这个哨所内的信使们也以同样的方式向其他哨所送信。直至所有n个哨所全部接到命令后，送信才算成功。因为准备充足，每个哨所内都安排了足够的信使（如果一个哨所与其他k个哨所有通信联系的话，这个哨所内至少会配备k个信使）。
    现在总指挥请你编一个程序，计算出完成整个送信过程最短需要多少时间。
输入
    输入第1行有两个整数n和m，中间用1个空格隔开，分别表示有n个哨所和m条通信线路。1<=n<=100。
    第2至m+1行：每行三个整数i、j、k，中间用1个空格隔开，表示第i个和第j个哨所之间存在通信线路，且这条线路要花费k天。
输出
    输出仅一个整数，表示完成整个送信过程的最短时间。如果不是所有的哨所都能收到信，就输出-1。
输入样例 1 
4 4
1 2 4
2 3 7
2 4 1
3 4 6
输出样例 1
11 */

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>

#define next Next

using namespace std;

const int MAXN = 1e4;
const int INF = 0x3f3f3f3f;

int n, m;
int ans, d[MAXN], v[MAXN];
int tot, head[MAXN], edge[MAXN], to[MAXN], next[MAXN];
queue<int> q;

void add(int x, int y, int z)
{
    edge[++tot] = z, to[tot] = y;
    next[tot] = head[x], head[x] = tot;
}

// SPFA单源最短路
void spfa()
{
    memset(d, 0x3f, sizeof(d));
    d[1] = 0, v[1] = true;
    q.push(1);
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        v[x] = false;
        for (int i = head[x]; i; i = next[i])
        {
            int y = to[i], z = edge[i];
            if (d[x] + z < d[y])
            {
                d[y] = d[x] + z;
                if (!v[y])
                    q.push(y), v[y] = true;
            }
        }
    }
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
    spfa();
    for (int i = 1; i <= n; i++)
    {
        if (d[i] == INF)
        {
            ans = -1;
            break;
        }
        ans = max(ans, d[i]);
    }
    printf("%d", ans);
    return 0;
}