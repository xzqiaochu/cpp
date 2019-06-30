// 最短路径(shopth) AC
#include <cstdio>
#include <cstdlib>
#include <queue>

using namespace std;

typedef long long int ll;

const int MAXN = 87;
const ll INF = 1e15;

int n, sta;
ll g[MAXN][MAXN], d[MAXN];
bool v[MAXN];
queue<ll> q;

void spfa()
{
    for (int i = 1; i <= n; i++)
        d[i] = INF;
    d[sta] = 0;
    q.push(sta), v[sta] = true;
    while (!q.empty())
    {
        int x = q.front();
        q.pop(), v[x] = false;
        for (int y = 1; y <= n; y++)
        {
            ll z = g[x][y];
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
    scanf("%d%d", &n, &sta);
    // for (int i = 1; i <= n; ++i)
    //     for (int j = 1; j <= n; ++j)
    //     {
    //         g[i][j] = INF;
    //         char c[20];
    //         scanf("%s", c);
    //         if (c[0] == '-' && not c[1])
    //             continue;
    //         g[i][j] = atoll(c);
    //     }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            ll temp = INF;
            scanf("%lld", &temp); // 如果输入的是 - ，则temp为初值 INF
            if (temp == INF)
                g[i][j] = INF;
            else
                g[i][j] = temp;
        }
    spfa();
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //         printf("%d ", g[i][j]);
    //     puts("");
    // }
    for (int i = 1; i <= n; i++)
    {
        if (i == sta || d[i] == INF)
            continue;
        printf("(%d -> %d) = %lld\n", sta, i, d[i]);
    }
    return 0;
}