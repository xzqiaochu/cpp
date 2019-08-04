// I - The Fewest Coins (https://vjudge.net/contest/316500#problem/I)
// POJ 3260
// from: USACO 2006 December Gold
// author: xzqiaochu
// status: AC
#include <cstdio>
#include <algorithm>

using std::min;

const int SZN = 107, SZM = 1e4 + 7, INF = 0x3f3f3f3f;

int n, t;
int v[SZN], num[SZN];
int f1[SZM], f2[SZM];
int ans = INF;

void dp2() // ÍêÈ«±³°ü 
{
	for (int i = 1; i <= SZM; i++)
		f2[i] = INF;
	f2[0] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = v[i]; j <= SZM; j++)
			 f2[j] = min(f2[j], f2[j - v[i]] + 1);
}

void ZeroOnePack(int val, int add = 1)
{
	for (int v = SZM; v >= val; v--)
		f1[v] = min(f1[v], f1[v - val] + add);
}

void CompletePack(int val)
{
	for (int v = val; v <= SZM; v++)
		f1[v] = min(f1[v], f1[v - val] + 1);
}

void MultiplePack(int val, int num)
{
	if (val * num >= SZM)
	{
		CompletePack(val);
		return;
	}
	for (int k = 1; k < num; k++)
		ZeroOnePack(k * val, k), num -= k;
	ZeroOnePack(num * val, num);
}

void dp1()
{
	for (int i = 1; i <= SZM; i++)
		f1[i] = INF;
	f1[0] = 0;
	for (int i = 1; i <= n; i++)
		MultiplePack(v[i], num[i]);
}

void calc()
{
	for (int i = t; i <= SZM; i++)
		ans = min(ans, f1[i] + f2[i - t]);
}

int main()
{
	scanf("%d%d", &n, &t);
	for (int i = 1; i <= n; i++)
		scanf("%d", v + i);
	for (int i = 1; i <= n; i++)
		scanf("%d", num + i);
	dp2();
	dp1();
	calc();
	if (ans == INF)
		printf("-1");
	else
		printf("%d", ans);
	return 0;
}
