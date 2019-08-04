// F - Piggy-Bank (https://vjudge.net/contest/316500#problem/F)
// POJ 1384£¬ZOJ 2014£¬HDOJ 1114
// from: ACM Central Europe 1999
// author: xzqiaochu
// status: AC
#include <cstdio>
#include <algorithm>

using std::min;

const int SZN = 507, SZM = 1e4 + 7, INF = 0x3f3f3f3f;

int n, m;
int w[SZN], c[SZN];
int f[SZM];

void init()
{
	for (int i = 1; i <= m; i++)
		f[i] = INF;
	f[0] = 0;
}

void dp()
{
	init();
	for (int i = 1; i <= n; i++)
		for (int v = w[i]; v <= m; v++)
			f[v] = min(f[v], f[v - w[i]] + c[i]); 
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		m = b - a;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d%d", c + i, w + i);
		dp();
		if (f[m] == INF)
			printf("This is impossible.\n");
		else
			printf("The minimum amount of money in the piggy-bank is %d.\n", f[m]);
	}
	return 0;
}
