// H - Coins (https://vjudge.net/contest/316500#problem/I)
// POJ 1742
// from: 做男人不容易系列：是男人就过8题--LouTiancheng题
// author: xzqiaochu
// status: AC
#include <cstdio>

const int SZN = 107, SZM = 1e5 + 7;

int n, m;
int v[SZN], num[SZN];
bool f[SZM];

void init()
{
	for (int i = 1; i <= m; i++)
		f[i] = 0;
	f[0] = 1;
}

void ZeroOnePack(int val)
{
	for (int j = m; j >= val; j--)
		f[j] = f[j] | f[j - val];
}

void CompletePack(int val)
{
	for (int j = val; j <= m; j++)
		f[j] = f[j] | f[j - val];
}

void MultiplePack(int val, int amount)
{
	if (val * amount >= m)
	{
		CompletePack(val);
		return;
	}
	for (int k = 1; k < amount; k *= 2)
		ZeroOnePack(k * val), amount -= k;
	ZeroOnePack(amount * val);
}

void dp()
{
	init();
	for (int i = 1; i <= n; i++)
		MultiplePack(v[i], num[i]);
}

int main()
{
	while (1)
	{
		scanf("%d%d", &n, &m);
		if (n == 0)
			break;
		for (int i = 1; i <= n; i++)
			scanf("%d", v + i);
		for (int i = 1; i <= n; i++)
			scanf("%d", num + i);
		dp();
		int cnt = 0;
		for (int i = 1; i <= m; i++)
			if (f[i])
				cnt++;
		printf("%d\n", cnt);
	}
	return 0;
}
