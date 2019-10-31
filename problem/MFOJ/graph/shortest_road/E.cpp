//信使(msner) AC
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