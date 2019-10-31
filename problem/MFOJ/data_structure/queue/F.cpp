//最小步数
#include <cstdio>
#include <queue>

using namespace std;

bool v[101][101];
int m1, n1, m2, n2, pro[12][2] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {2, 2}, {2, -2}, {-2, 2}, {-2, -2}};
struct xy_sut
{
	int x, y;
};
queue<xy_sut> q;

inline bool judge(int x, int y)
{
	if (x >= 1 && x <= 100 && y >= 1 && y <= 100 && v[x][y] == 0)
		return true;
	else
		return false;
}

bool bfs()
{
	xy_sut sta;
	sta.x = 1;
	sta.y = 1;
	v[1][1] = 1;
	q.push(sta);
	while (!q.empty())
	{
		xy_sut now;
		now = q.front();
		q.pop();
		if (now.x == m1 && now.y == n1)
			return 1;
		if (now.x == m2 && now.y == n2)
			return 0;
		for (int i = 0; i <= 11; i++)
		{
			xy_sut next;
			next.x = now.x + pro[i][0];
			next.y = now.y + pro[i][1];
			if (judge(next.x, next.y))
			{
				v[next.x][next.y] = 1;
				q.push(next);
			}
		}
	}
}

int main()
{
	scanf("%d%d%d%d", &m1, &n1, &m2, &n2);
	if (bfs())
		printf("Alice");
	else
		printf("Bob");
	return 0;
}