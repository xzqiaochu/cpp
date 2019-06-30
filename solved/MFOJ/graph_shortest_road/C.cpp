//最小花费(money) AC
#include <cstdio>
#include <queue>

using namespace std;

#define next Next

const int MAXN = 1000005;

bool v[MAXN];
int tot, n, m, a, b, head[MAXN], to[MAXN], edge[MAXN], next[MAXN];
double d[MAXN];
queue<int> q;

inline void add(int x, int y, int z)
{
    edge[++tot] = z, to[tot] = y;
    next[tot] = head[x], head[x] = tot;
}

void spfa()
{
    d[a] = 1, v[a] = true;
    q.push(a);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        v[x] = false;
        for (int i = head[x]; i; i = next[i])
        {
            int y = to[i], z = edge[i];
            if ((double)d[x] * z / 100 > d[y])
            {
                d[y] = (double)d[x] * z / 100;
                if (!v[y])
                {
                    q.push(y);
                    v[y] = true;
                }
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
        add(x, y, 100 - z);
        add(y, x, 100 - z);
    }
    scanf("%d%d", &a, &b);
    spfa();
    printf("%.8f", 100 / d[b]);
    return 0;
}