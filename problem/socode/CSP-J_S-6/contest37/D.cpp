//D-信心满满
//http://socode.online/problems/369?contest=37
//author: xzqiaochu
//status: AC
//time: 2019/11/10 
//algorithm: 并查集 快速幂 
#include <cstdio>
const int SZ = 1e5;
const int MOD = 1000000007;

int n, k;
int fa[SZ], sz[SZ];
int ans;

int qpow(int a, int b) {
	int x = 1;
	while (b) {
		if (b & 1)
			x = 1LL * x * a % MOD;
		a = 1LL * a * a % MOD;
		b >>= 1;
	}
	return x;
}

int getRoot(int x) {
	if (fa[x] == x)
		return x;
	return fa[x] = getRoot(fa[x]);
}

void merge(int x, int y) {
	int rtx = getRoot(x), rty = getRoot(y);
	if (rtx == rty)
		return;
	fa[rtx] = rty;
	sz[rty] += sz[rtx];
}

int main() {
	scanf("%d%d", &n, &k);
	ans = qpow(n, k);
	for (int i = 1; i <= n; i++)
		fa[i] = i, sz[i] = 1;
	for (int i = 1; i <= n - 1; i++) {
		int x, y, f;
		scanf("%d%d%d", &x, &y, &f);
		if (f == 0)
			merge(x, y);
	}
	for (int i = 1; i <= n; i++)
		if (fa[i] == i)
			ans = (1LL * ans - qpow(sz[i], k) + MOD) % MOD;
	printf("%d", ans);
	return 0;
} 
