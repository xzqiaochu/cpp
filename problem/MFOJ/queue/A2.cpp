//面积
#include <cstdio>
#include <queue>

using namespace std;

int a[12][12], pro[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
struct xy_sut
{
    int x, y;
};
queue<xy_sut> q;

bool judge(int x, int y)
{
    if (x >= 0 && x <= 11 && y >= 0 && y <= 11 && a[x][y] == 0)
        return true;
    else
        return false;
}

void mark()
{
    xy_sut sta;
    sta.x = 0;
    sta.y = 0;
    q.push(sta);
    while (!q.empty())
    {
        xy_sut now;
        now = q.front();
        q.pop();
        for (int i = 0; i <= 3; i++)
        {
            xy_sut next;
            next.x = now.x + pro[i][0];
            next.y = now.y + pro[i][1];
            if (judge(next.x, next.y))
            {
                a[next.x][next.y] = 1;
                q.push(next);
            }
        }
    }
}

int main()
{
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++)
            scanf("%d", &a[i][j]);
    mark();
    int cnt = 0;
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++)
            if (a[i][j] == 0)
                cnt++;
    printf("%d", cnt);
    // puts("");
    // for (int i = 1; i <= 10; i++)
    // {
    // 	for (int j = 1; j <= 10; j++)
    // 	{
    // 		printf("%d ", a[i][j]);
    // 	}
    // 	puts("");
    // }
    return 0;
}