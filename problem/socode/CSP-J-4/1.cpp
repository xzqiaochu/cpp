// CSP-J-A 信号灯
// author: xzqiaochu
// status: AC
// time: 2019/10/28 
#include <cstdio>

typedef long long int64;

int64 n;
int a, b, c;

void prt(int f)
{
	switch (f)
	{
		case 0:
			puts("Red");
			break;
		case 1:
			puts("Yellow");
			break;
		case 2:
			puts("Green");
			break;
	}
}

int main()
{
	scanf("%lld", &n);
	n -= 1;
	n %= 27;
	
	a = n % 3;
	n /= 3;
	
	b = n % 3;
	n /= 3;

	c = n % 3;
	
	prt(a), prt(b), prt(c);
	return 0;
} 
