// 361-º£µÁ·Ö½ð±Ò
// author: xzqiaochu
// status: AC
// time: 2019/11/1
#include <cstdio>
#include <cmath>

int main()
{
	int n, ans;
	scanf("%d", &n);
	ans = log2(n);
	ans = pow(2, ans);
	printf("%d",ans);
	return 0;
}
