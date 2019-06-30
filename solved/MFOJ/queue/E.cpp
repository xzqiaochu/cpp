//细胞
#include <cstdio>

bool a[61][61];
int m, n, cnt;

void mark(int x, int y)
{
	if (x < 0 || x > m || y < 0 || y > n)
		return;
	if (a[x][y] == 0)
		return;
	a[x][y] = 0;
	mark(x + 1, y);
	mark(x - 1, y);
	mark(x, y + 1);
	mark(x, y - 1);
}

int main()
{
	scanf("%d%d", &m, &n);
	getchar();
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
			a[i][j] = getchar() - '0'; 
		getchar();
	}
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
		{
			if (a[i][j] == 1)
			{
				cnt++;
				mark(i, j);
			}
		}
	printf("%d", cnt);
	return 0;
}