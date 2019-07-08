// 灯笼草(lantern)
// author: xzqiaochu
// status: MTL
#include <cstdio>

const int MAXN = 1e4 + 7;

int n, m, a[MAXN][MAXN], fx[MAXN][MAXN], fy[MAXN][MAXN];

void init()
{
	for (int i = 1; i <= n + 1; i++)
		for (int j = 1; j <= m + 1; j++)
			fx[i][j] = fy[i][j] = 0;
}

bool check(int r)
{
	init();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			if (a[i][j] >= r)
			{
				int ya = i - r + 1;
				ya = ya < 1 ? 1 : ya;
				int yb = i + r - 1;
				yb = yb > n ? n : yb;
				fy[ya][j] -= 1;
				fy[yb + 1][j] += 1;
				
				int xa = j - r + 1;
				xa = xa < 1 ? 1 : xa;
				int xb = j + r - 1;
				xb = xb > m ? m : xb;
				fx[i][xa] -= 1;
				fx[i][xb + 1] += 1;
			}
		}
	// fx
	for (int i = 1; i <= n; i++) // y
		for (int j = 1, s = 0; j <= m; j++) // x
		{
			s += fx[i][j];
			if (s == 0)
				return false;
		}
	// fy
	for (int j = 1; j <= m; j++) // x
		for (int i = 1, s = 0; i <= n; i++) // y
		{
			s += fy[i][j];
			if (s == 0)
				return false;
		}
	return true;
}

int main()
{
	// freopen("lantern.in", "r", stdin);
	// freopen("lantern.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	for (int i = 1; i <= 1e9; i++)
		if (check(i))
		{
			printf("%d", i);
			break;
		}
	return 0;
}
