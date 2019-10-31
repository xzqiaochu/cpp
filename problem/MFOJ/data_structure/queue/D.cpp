//家庭问题
#include <cstdio>
#include <algorithm>

using namespace std;

int n, k, cnt, maxn, fa[101], sz[101];

int getroot(int n)
{
	if (fa[n] == n)
		return n;
	return fa[n] = getroot(fa[n]);
}

void merge(int u, int v)
{
	int rtu = getroot(u), rtv = getroot(v);
	if (rtu == rtv)
		return;
	if (rtu > rtv)
		fa[rtv] = rtu, sz[rtu] += sz[rtv];
	else
		fa[rtu] = rtv, sz[rtv] += sz[rtu];
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		fa[i] = i, sz[i] = 1;
	for (int i = 1, u, v; i <= k; i++)
	{
		scanf("%d%d", &u, &v);
		merge(u, v);
	}
	for (int i = 1; i <= n; i++)
		if (fa[i] == i)
		{
			cnt++;
			maxn = max(maxn, sz[i]);
		}
	printf("%d %d", cnt, maxn);
	return 0;
}