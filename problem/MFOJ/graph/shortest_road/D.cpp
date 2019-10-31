//香甜的黄油(butter) AC
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>

#define next Next

using namespace std;

const int MAXN = 3000;
const int INF = 0x3f3f3f3f;

int n, p, c, cow[MAXN];
int ans = INF, d[MAXN], v[MAXN];
int tot, head[MAXN], edge[MAXN], to[MAXN], next[MAXN];
queue<int> q;

void add(int x, int y, int z)
{
    edge[++tot] = z, to[tot] = y;
    next[tot] = head[x], head[x] = tot;
}

void spfa(int st)
{
    memset(d, 0x3f, sizeof(d));
    d[st] = 0, v[st] = true;
    q.push(st);
    while (!q.empty())
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
    scanf("%d%d%d", &n, &p, &c);
    for (int i = 1; i <= n; i++)
        scanf("%d", cow + i);
    for (int i = 1; i <= c; i++)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z);
        add(y, x, z);
    }
    for (int i = 1; i <= p; i++)
    {
        bool success = true;
        int sum = 0;
        spfa(i);
        for (int j = 1; j <= n; j++)
        {
            if (d[cow[j]] == INF)
            {
                success = false;
                break;
            }
            sum += d[cow[j]];
        }
        if (success)
            ans = min(ans, sum);
    }
    printf("%d", ans);
    return 0;
}