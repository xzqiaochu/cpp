// B-货币系统(money)
// http://www.mfstem.org/contest/28/problem/B
// author: xzqiaochu
// status: AC
// time: 2019/11/02
#include <cstdio>
#include <cstring>
#include <algorithm>

const int NSZ = 107, MSZ = 25007;

int n, a[NSZ], f[MSZ];

int calc() {
	int ans = n;
	std::sort(a+1, a+n+1);
	memset(f, 0, sizeof(f));
	f[0] = true;
	for (int i = 1; i <= n; i++) {
		if (f[a[i]]) {
			ans--;
			continue;
		}
		for (int j = a[i]; j <= MSZ; j++)
			f[j] |= f[j-a[i]];
	}
	return ans;
}

int main() {
//	freopen("money.in", "r", stdin);
//	freopen("money.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", a + i);
		printf("%d\n", calc());
	}
	return 0;
}