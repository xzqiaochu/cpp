//找树根和孩子
#include <cstdio>
#include <algorithm>

using namespace std;

int n, m, fa[201], sz[201], a[201];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		fa[y] = x, sz[x]++;
	}
	int root;
	int maxfa, maxn = 0;
	for (int i = 1; i <= n; i++)
	{
		if (fa[i] == 0)
			root = i;
		if (sz[i] > maxn)
		{
			maxfa = i;
			maxn = sz[i];
		}
	}
	printf("%d\n%d\n", root, maxfa);
	int p = 0;
	for (int i = 1; i <= n; i++)
		if (fa[i] == maxfa)
			a[++p] = i;
	sort(a + 1, a + p + 1);
	for (int i = 1; i <= p; i++)
		printf("%d ", a[i]);
	return 0;
}