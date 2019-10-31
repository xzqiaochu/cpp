// A-íÀÂë³ÆÖØ(weight)
// http://www.mfstem.org/contest/54/problem/A
// author: xzqiaochu
// status: AC
// time: 2019/10/31
#include <cstdio>

const int NSZ = 7, MSZ = 1007;
const int val[] = {0, 1, 2, 3, 5, 10, 20};

int num[NSZ];
bool f[MSZ];

void zeroOnePack(int val)
{
	for (int i = 1000; i >= val; i--)
		f[i] |= f[i - val];
}

void dp()
{
	f[0] = true;
	for (int i = 1; i <= 6; i++)
	{
		int amount = num[i];
		for (int k = 1; ; k *= 2)
		{
			if (k < amount)
				zeroOnePack(k * val[i]), amount -= k;
			else
				break;
		}
		zeroOnePack(amount * val[i]);
	}
}

int main()
{
	for (int i = 1; i <= 6; i++)
		scanf("%d", num + i);
	dp();
	int cnt = 0;
	for (int i = 1; i <= 1000; i++)
		if (f[i])
			cnt++;
	printf("Total=%d", cnt);
	return 0;
} 
