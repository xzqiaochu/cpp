//奇怪的电梯
#include <cstdio>
#include <queue>

using namespace std;

int n, sta, tar, k[201], v[201];
queue<int> q;

bool judge(int x)
{
    if (x >= 1 && x <= n && v[x] == 0)
        return true;
    else
        return false;
}

int bfs()
{
    q.push(sta);
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        if (now == tar)
            return v[now];
        int next = now + k[now];
        if (judge(next))
        {
            v[next] = v[now] + 1;
            q.push(next);
        }
        next = now - k[now];
        if (judge(next))
        {
            v[next] = v[now] + 1;
            q.push(next);
        }
    }
    return -1;
}

int main()
{
    scanf("%d%d%d", &n, &sta, &tar);
    for (int i = 1; i <= n; i++)
        scanf("%d", k + i);
    printf("%d", bfs());
    return 0;
}