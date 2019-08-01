#include <cstdio>
#include <algorithm>

const long long MAXN = 500007, INF = 0x3f3f3f3f3f3f3f3f;

long long n, k, a[MAXN], s[MAXN], b[MAXN], f[MAXN];

using namespace std;

void init()
{
	for (int i = 1; i <= n; i++)
		f[i] = INF;
	f[0] = 0;
}

int main()
{
	// freopen("empire.in", "r", stdin);
	// freopen("empire.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i), s[i] = s[i - 1] + a[i];
	for (int i = 0; i <= n - 1; i++)
		scanf("%d", b + i);
	init();
	for (int i = 1; i <= n; i++)
		for (int j = std::max(i - k, 0ll); j <= i - 1; j++)
			f[i] = std::min(f[i], f[j] + std::max(b[j], s[i] - s[j]));
//	for (int i = 1; i <= n; i++)
//		 printf("%d\n", f[i]);
	printf("%lld", f[n]);
	return 0;
}
