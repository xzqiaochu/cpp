// B-×îÐ¡²î 
// https://ac.nowcoder.com/acm/contest/1093/B
// author: xzqiaochu
// status: AC
// time: 2019/11/03
#include <cstdio>
#include <algorithm> 
const int SZ = 100007, INF = 0x3f3f3f3f;

int n, k, a[SZ], ans = INF;

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	std::sort(a+1, a+n+1);
	int len = n - k;
	for (int i = 1; i + len - 1 <= n; i++) {
		int end = i + len - 1;
		ans = std::min(ans, a[end] - a[i]);
	}
	printf("%d", ans);
	return 0;
}
