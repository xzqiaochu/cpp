#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long int64;
const int M = 1e9 + 7;
const int N = 3e5 + 7;

int n, m, k, hd[N], egs, ids, c[N]; //c为树状数组
int id[N], tp[N], son[N], sz[N], fa[N], dep[N]; //树链剖分用
int fac[N], ifac[N], inv[N]; //求组合数

struct Range {
	int x, y, lca;
	bool operator< (const Range &b) const {
		return lca < b.lca;
	}
} r[N];

struct Edge {
	int u, v, next;
} eg[N<<1];

inline void addEdge(int u, int v) {
	eg[++egs] = Edge{u, v, hd[u]};
	hd[u] = egs;
}

void update(int x, int y) {
	for (int i = 1; i < N; i += i & -i)
		c[i] += y;
}

int getSum(int x) {
	int ans = 0;
	for (int i = x; i; i -= i & -i)
		ans += c[i];
	return ans;
}

void dfs1(int u) {
	son[u] = 0, dep[u] = dep[fa[u]] + 1, sz[u] = 1;
	for (int i = hd[u]; i; i = eg[i].next) {
		int v = eg[i].v;
		if (v == fa[v])
			continue;
		fa[v] = u;
		dfs1(v);
		sz[u] += sz[v];
		if (sz[v] > sz[son[u]])
			son[u] = v;
	}
}

void dfs2(int u, int f) { //f链顶 
	tp[u] = f, id[u] = ++ids;
	if (son[u])
		dfs2(son[u], f);
	for (int i = hd[u]; i; i = eg[i].next) {
		int v = eg[i].v;
		if (v != son[u] && v != fa[u])
			dfs2(v, v);
	}
}

void contribute(int u, int v) {
	int tp1 = tp[u], tp2 = tp[v];
	while (tp1 != tp2) {
		if (dep[tp1] < dep[tp2])
			std::swap(u, v);
		update(id[tp1], 1), update(id[u] + 1, -1);
		u = fa[tp1], tp1 = tp[u];
	}
	if (dep[u] > dep[v])
		std::swap(u, v);
	update(id[u], 1), update(id[v] + 1, -1);
}

int LCA(int u, int v) {
	if (u == v)
		return u;
	int tp1 = tp[u], tp2 = tp[v];
	while (tp1 != tp2) {
		if (dep[tp1] < dep[tp2])
			std::swap(tp1, tp2), std::swap(u, v);
		u = fa[tp1], tp1 = tp[u];
	}
	if (dep[u] > dep[v])
		std::swap(u, v);
	return u;
}

void init() {
	fac[0] = ifac[0] = inv[0] = 1;
	fac[1] = ifac[1] = inv[1] = 1;
	for (int i = 2; i < N; i++) {
		fac[i] = 1LL * fac[i - 1] * i % M;
		inv[i] = 1LL * (M - M / i) * inv[M % i] % M;
		ifac[i] = 1LL * ifac[i - 1] * inv[i] % M;
	}
}

inline int C(int n, int m) {
	if (m > n)
		return 0;
	return 1LL * fac[n] * ifac[n-m] % M * ifac[m] % M;
}

int main() {
	int T;
	scanf("%d", &T);
	init();
	while (T--) {
		int64 ans = 0;
		egs = ids = 0;
		memset(c, 0, sizeof(c));
		memset(hd, 0, sizeof(hd));
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 1; i <= n; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			addEdge(u, v), addEdge(u, v); 
		}
		dfs1(1), dfs2(1, 1);
		for (int i = 1; i <= m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			r[i] = Range{u, v, LCA(u, v)};
		}
		std::sort(r+1, r+m+1);
		for (int i = 1; i <= n; i++) {
			ans = (ans + C(getSum(id[r[i].lca]), k-1)) % M;
			contribute(r[i].x, r[i].y);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
