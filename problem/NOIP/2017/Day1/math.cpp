//[NOIP2017]-Day1-A-С�����ɻ�(math)
//http://www.mfstem.org/contest/26/problem/A
//author: xzqiaochu
//status: AC
//algorithm: �������ƹ�ʽ
//time: 2019/11/12
#include <cstdio>
#include <ctime>
typedef long long int64;

int64 a, b;

int main() {
	freopen("math.in", "r", stdin);
	freopen("math.out", "w", stdout);
	scanf("%lld%lld", &a, &b);
	printf("%lld", a * b - a - b);
	return 0;
} 
