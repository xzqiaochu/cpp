// ¼òµ¥Ä£ÄâÌâ (im.in/out)
// author: xzqiaochu
// status: AC 
// time: 2019/11/04
#include <cstdio>
typedef long long ll;
const int SZ = 1e5 + 7;

ll n, a[SZ];
char type[SZ];
ll e, time;

int main() {
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lld", a + i);
	scanf("%s", type + 1);
	for (int i = 1; i <= n; i++) {
		if (type[i] == 'W')
			e += a[i], time += a[i] * 3;
		else {
			if (e >= a[i])
				e -= a[i], time += a[i];
			else {
				time += e;
				ll left = a[i] - e;
				e = 0;
				time += left * 3;			
			}
		}
	}
	time -= e;
	printf("%lld", time);
	return 0;
}
