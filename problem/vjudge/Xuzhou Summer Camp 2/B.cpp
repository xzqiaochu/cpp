// B - Dollars (https://vjudge.net/contest/316500#problem/B)
// UVA 147
// from: New Zealand Contest 1991
// author: xzqiaochu (Rewrite from the Internet)
// status: AC
// Why cant't begin from 1 ?
#include <cstdio>

const int SZM = 6007;

int m;
int v[] = {5,10,20,50,100,200,500,1000,2000,5000,10000};
long long f[SZM];

void dp() {
	f[0] = 1; // Why cant't begin from 1 ?
	for(int i = 0; i < 11; i++)
		for(int j = v[i]; j < SZM; j++)
			f[j] += f[j - v[i]];
}

int main()
{
	dp();
	while (1)
	{
		double temp;
		scanf("%lf", &temp);
		if (temp == 0)
			break;
		m = temp * 100;
		printf("%6.2lf%17lld\n", temp, f[m]);
	}
	return 0;
}
