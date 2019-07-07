#include <cstdio>
#include <cstring>
#include <utility>
#include <queue>

#define next Next

using namespace std;

const int MAXN = 107, INF = 0x3f3f3f3f;

int pro[8][2] =
{
{1, 2},
{2, 1},
{-1, 2},
{2, -1},
{1, -2},
{-2, 1},
{-1, -2},
{-2, -1}
};
int m, n, sta, tar, a[MAXN][MAXN]; // 共 m 行，n 列
int tot, head[MAXN * MAXN], ver[16 * MAXN * MAXN], edge[16 * MAXN * MAXN], next[16 * MAXN * MAXN];
int d[MAXN * MAXN];
bool v[MAXN * MAXN];
priority_queue< pair<int, int> > q;

inline void add(int x, int y, int z)
{
	ver[++tot] = y, edge[tot] = z;
	next[tot] = head[x], head[x] = tot;
}

inline int getID(int x, int y)
{
	return (x - 1) * n + y;
}

inline bool judge(int x, int y) // 第 x 行，y 列
{
	if (x >= 1 && x <= m && y >= 1 && y <= n)
		return true;
	return false; 
}

void init()
{
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
		{
			int x = getID(i, j);
			if (a[i][j] == 3)
				sta = x;
			if (a[i][j] == 4)
				tar = x;
			for (int k = 0; k < 8; k++)
			{
				int next_x = i + pro[k][0];
				int next_y = j + pro[k][1];
				if (!judge(next_x, next_y))
					continue;
				int y = getID(next_x, next_y);
				int status = a[next_x][next_y];
				if (status == 0)
					add(x, y, m * n + 1);
				if (status == 1 || status == 3 || status == 4)
					add(x, y, 1);
				if (status == 2)
					add(x, y, INF);
			}
		}
}

bool dijkstra()
{
	memset(d, 0x3f, sizeof(d));
	d[sta] = 0;
	q.push(make_pair(0, sta));
	while (!q.empty())
	{
		int x = q.top().second;
		q.pop();
		if (x == tar)
			return true;
		if (v[x])
			continue;
		v[x] = true;
		for (int i = head[x]; i; i = next[i])
		{
			int y = ver[i], z = edge[i];
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
	freopen("lilypad.in", "r", stdin);
	freopen("lilypad.out", "w", stdout);
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	init();
	if (dijkstra())
		printf("%d %d", d[tar] / (m * n), d[tar] % (m * n));
	else
		printf("-1 -1");
	return 0;
}
