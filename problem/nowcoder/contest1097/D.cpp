//牛客CSP-J入门组赛前集训营5-D-终焉之理
//https://ac.nowcoder.com/acm/contest/1097/D
//author: xzqiaochu
//status: AC
//time: 2019/11/10
#include <cstdio>
#include <utility>
#include <algorithm>
const int SZ = 1e5 + 7;

int n, k, maxn, ans;
std::pair<int, int> a[SZ];

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		maxn = 0;
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++) {
			int tmp;
			scanf("%d", &tmp);
			a[i] = std::make_pair(tmp, i);
		}
		std::sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; i++) {
			if (a[i].second - i > 0)
				maxn = std::max(maxn, a[i].second - i);
		}
		ans = (maxn + k - 2) / (k - 1);
		printf("%d\n", ans);
	}
	return 0;
}
