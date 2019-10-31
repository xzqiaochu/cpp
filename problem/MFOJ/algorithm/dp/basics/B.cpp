// B-����½�����(LIS)
// http://www.mfstem.org/contest/53/problem/B
// author: xzqiaochu
// status: PAC�������ң�����OJû��special judge)
// time: 2019/10/30
#include <cstdio>
#include <algorithm>

using std::max;

const int SZ = 105;

int n, a[SZ];
int rank[SZ], f[SZ], pre[SZ], out[SZ];
int ans, end;

void calc()
{
	// rank[����] = �±� 
	int maxn = 0; // ����½������еĳ��� 
	for (int i = 1; i <= a[0]; i++)
	{
		int t = maxn; // t������ 
		while (t > 0 && a[rank[t]] > a[i]) // ��һ������ת�Ƶ�Ԫ�� 
			t--;
		f[i] = f[rank[t]] + 1; // f[0] = 0
		if (rank[f[i]] == 0 || a[i] < a[ rank[f[i]] ])
			rank[f[i]] = i;
        pre[i] = rank[t];
		if (f[i] > maxn)
		{
			maxn = f[i];
			end = i; 
		}
	}
	ans = maxn;
}

void print()
{
	printf("max=%d\n", ans);
	int p = end;
	while (p)
	{
		out[++out[0]] = a[p];
		p = pre[p];
	}
	for (int i = out[0]; i >= 1; i--)
		printf("%d ", out[i]);
}

int main()
{
	int tmp;
	while (~scanf("%d", &tmp))
		a[++a[0]] = tmp;
	calc();
	print();
	return 0;
}
