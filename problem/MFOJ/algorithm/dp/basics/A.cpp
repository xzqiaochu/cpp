// A-Êý×Ö½ð×ÖËþ(tower)
// http://www.mfstem.org/contest/53/problem/A
// author: xzqiaochu
// status: AC
// time: 2019/10/30 
#include <cstdio>
#include <algorithm>

using std::max;

const int SZ = 1005, INF = 0x3f3f3f3f;

int n, a[SZ][SZ], f[SZ][SZ];

void dp()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			f[i][j] = max(f[i-1][j], f[i-1][j-1]) + a[i][j];
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			scanf("%d", &a[i][j]);
	dp();
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(ans, f[n][i]);
	printf("%d\n", ans);
	return 0;
}

