// chocolate
// author: xzqiaochu
// status: AC
#include <cstdio>
#include <cstring>

const int MAXN = 30;

int n, m, k, per, a[MAXN][MAXN], s[MAXN][MAXN];
bool f[MAXN][MAXN][MAXN][MAXN], v[MAXN][MAXN][MAXN][MAXN];

void init()
{
	memset(f, 0, sizeof(f));
	memset(v, 0, sizeof(v));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
}

inline int getSum(int xa, int xb, int ya, int yb)
{
	return s[xb][yb] - s[xa - 1][yb] - s[xb][ya - 1] + s[xa - 1][ya - 1];
}

bool dfs(int xa, int xb, int ya, int yb)
{
	if (v[xa][xb][ya][yb])
		return f[xa][xb][ya][yb];
	v[xa][xb][ya][yb] = true;
	int sum = getSum(xa, xb, ya, yb);
	if (sum == per)
		return f[xa][xb][ya][yb] = true;
	// 横着切
	for (int i = xa; i <= xb - 1; i++)
	{
		if (getSum(xa, i, ya, yb) % per == 0 && getSum(i + 1, xb, ya, yb) % per == 0)
			if (dfs(xa, i, ya, yb) && dfs(i + 1, xb, ya, yb))
				return f[xa][xb][ya][yb] = true;
	}
	// 竖着切
	for (int i = ya; i <= yb - 1; i++)
	{
		if (getSum(xa, xb, ya, i) % per == 0 && getSum(xa, xb, i + 1, yb) % per == 0)
			if (dfs(xa, xb, ya, i) && dfs(xa, xb, i + 1, yb))
				return f[xa][xb][ya][yb] = true;
	}
	return f[xa][xb][ya][yb] = false;
}

int main()
{
	// freopen("chocolate.in", "r", stdin);
	// freopen("chocolate.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int sum = 0;
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				scanf("%d", &a[i][j]), sum += a[i][j];
		if (sum % k != 0)
			puts("NO");
		else
		{
			per = sum / k;
			init();
			if (dfs(1, n, 1, m) || dfs(1, n, 1, m))
				puts("YES");
			else
				puts("NO");
		}
	}
	return 0;
}