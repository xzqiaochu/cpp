// B-◊∞œ‰Œ Ã‚(boxes)
// http://www.mfstem.org/contest/54/problem/B
// author: xzqiaochu
// status: AC
// time: 2019/10/31
#include <cstdio>
#include <algorithm>

using std::max;

const int NSZ = 37, MSZ = 20007;

int n, m, a[NSZ], f[MSZ];

void dp()
{
	for (int i = 1; i <= n; i++)
		for (int j = m; j >= a[i]; j--)
			f[j] = max(f[j], f[j - a[i]] + a[i]);
}

int main()
{
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	dp();
	printf("%d", m - f[m]);
	return 0;
} 
