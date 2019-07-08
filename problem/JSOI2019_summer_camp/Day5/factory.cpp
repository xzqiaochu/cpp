// Problem 1 嚎叫响彻在贪婪的厂房(factory)
// Author: xzqiaochu
// status: AC
#include <cstdio>
#include <cmath>
#include <set>

using namespace std;

const int MAXN = 100007;

int n, a[MAXN], add[MAXN];

int gcd(int x, int y)
{
	if (x == 0)
		return y;
	return gcd(y % x, x);
}

int main()
{
	// freopen("factory.in", "r", stdin);
	// freopen("factory.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", a + i);
		add[i] = std::abs(a[i] - a[i - 1]);
	}
	int cnt = 1, maxgcd = 0; 
	set<int> *rcd = new set<int>;
	rcd->insert(a[1]);
	for (int i = 2; i <= n; i++)
	{
		maxgcd = gcd(maxgcd, add[i]);
		if (rcd->count(a[i]) == 1 || maxgcd == 1)
		{
			cnt++, maxgcd = 0;
			delete rcd;
			rcd = new set<int>;
			rcd->insert(a[i]);
		}
		rcd->insert(a[i]);
	}
	printf("%d", cnt);
	return 0;
}