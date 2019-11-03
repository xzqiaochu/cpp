// 364-Î±½×³ËÊý
// author: xzqiaochu
// status: AC
// time: 2019/11/1
#include <cstdio>
#include <algorithm>

using namespace std;

typedef __int128 ll;

const int SZ = 1e7;
const ll T = 1e18;
const ll a[20] = {1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800,
87178291200,1307674368000,20922789888000,355687428096000,6402373705728000,121645100408832000};

int cnt = 0;
ll tbl[SZ];

//void write(ll k)
//{
//	if (k==0) putchar('0');
//	if (k>9)
//		write(k/10);
//	putchar(k%10+'0');
//}

void dfs(int k, ll s)
{
	if (s > T)
		return;
	if (k == 20)
	{
		tbl[++cnt] = s;
		return;
	}
	tbl[++cnt] = s;
	dfs(k, s*a[k]);
	dfs(k+1, s);
}

int main()
{
	dfs(2, 1);
	sort(tbl+1, tbl+cnt+1);
	cnt = unique(tbl+1, tbl+cnt+1) - (tbl+1);
	int T;
	scanf("%d", &T);
	while (T--)
	{
		long long a;
		scanf("%lld", &a);
		if (tbl[lower_bound(tbl+1, tbl+cnt+1, a)-tbl] == a)
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}

