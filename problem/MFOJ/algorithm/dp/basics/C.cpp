// C-拦截导弹(missile)
// http://www.mfstem.org/contest/53/problem/C
// author: xzqiaochu
// status: AC
// time: 2019/10/31 
#include <cstdio>
#include <algorithm>

using std::max; 

const int SZ = 100, INF = 0x3f3f3f3f;

int a[SZ], f[SZ], rank[SZ];
int sys[SZ];

int calc1()
{
	int maxn = 0;
	for (int i = 1; i <= a[0]; i++)
	{
		int t = maxn; // t不是下标！必须用 rank[t] 
		while (t > 0 && a[ rank[t] ] < a[i])
			t--;
		f[i] = f[rank[t]] + 1;
		maxn = max(maxn, f[i]);
		if (rank[f[i]] == 0 || a[i] > a[ rank[f[i]] ])
			rank[f[i]] = i;
	}
	return maxn;
}

int calc2()
{
	for (int i = 1; i <= a[0]; i++)
	{
		bool success = false;
		int minsys = INF, p = 0; 
		for (int j = 1; j <= sys[0]; j++)
			if (sys[j] >= a[i] && sys[j] < minsys) // 可用并且更优 
				success = true, minsys = sys[i], p = j;
		if (success)
			sys[p] = a[i];
		else
			sys[++sys[0]] = a[i];
	}
	return sys[0]; 
}

int main()
{
	int tmp;
	while (~scanf("%d", &tmp))
		a[++a[0]] = tmp;
	printf("%d\n%d\n", calc1(), calc2());
	return 0; 
}

