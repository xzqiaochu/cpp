// D - Pass-Muraille  (https://vjudge.net/contest/316356#problem/D)
// auhtor: xzqiaochu
// status: WA
#include <cstdio>
#include <cstring>
#include <set>
#include <utility>

using namespace std;

int n, k;
bool g[107][107];

void del(int num, int x)
{
	set< pair<int, int> > a;
	for (int y = 0; y <= 100; y++)
		if (g[x][y] == 1)
		{
			int end;
			for (end = x; g[end][y]; end++){}
			a.insert(make_pair(end - x, y));
		}
	set< pair<int, int> >::iterator iter = a.end();
	for (int i = 1; i <= num; i++)
	{
		iter--;
		int y = iter->second;
		for (int j = x; g[j][y]; j++)
			g[j][y] = 0;
	}
}

int calc()
{
	int rst = 0;
	for (int x = 0; x <= 100; x++)
	{
		int cnt = 0;
		for (int y = 0; y <= 100; y++)
			if (g[x][y] == 1)
				cnt++;
		if (cnt > k)
			del(cnt - k, x), rst++;
	}
	return rst;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		memset(g, 0, sizeof(g));
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++)
		{
			int x1, y1, x2, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			for (int x = x1; x <= x2; x++)
				g[x][y1] = 1;
		}
		printf("%d\n", calc());
	}
	return 0;
}
