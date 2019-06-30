//面积
#include <cstdio>

int a[11][11];

bool mark(int x, int y)
{
	if (x < 0 || x > 10 || y < 0 || y > 10)
		return false;
	if (a[x][y] == 1 || a[x][y] == 2)
		return true;
	a[x][y] = 2;
	if (mark(x - 1, y) && mark(x + 1, y) && mark(x, y - 1) && mark(x, y + 1))
        return true;
	else
	{
        a[x][y] = 0;
		for (int i = x; i <= 10; i++)
        {
            if (a[i][y] == 1)
                break;
            a[i][y] = 0;
        }
        for (int i = x; i >= 0; i--)
        {
            if (a[i][y] == 1)
                break;
            a[i][y] = 0;
        }
        for (int i = y; i <= 10; i++)
        {
            if (a[x][i] == 1)
                break;
            a[x][i] = 0;
        }
        for (int i = y; i >= 0; i--)
        {
            if (a[x][i] == 1)
                break;
            a[x][i] = 0;
        }
		return false;
	}
}

int main()
{
	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 10; j++)
			scanf("%d", &a[i][j]);
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			if (a[i][j] == 0)
				mark(i, j);
		}
	}
    int cnt = 0;
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++)
            if (a[i][j] == 2)
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