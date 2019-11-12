// [NOIP2018]Day2-C-保卫王国(defense)
// http://www.mfstem.org/contest/29/problem/C
// author: xzqiaochu
// status: PAC(11/25) 
// algorithm: 暴力dp 
// time: 2019/11/07
#include <cstdio>
#include <algorithm>
using std::min;
typedef long long int64;
const int VSZ = 3e5 + 7, ESZ = VSZ * 2;
const int64 INF = 1e18, EPS = 1000;

int n, q;

int v[VSZ];
int head[VSZ];
struct Edge {
	int to, next;
} edge[ESZ];

int must[2], mustnot[2];
int64 f[VSZ][2];
int64 ans;

inline void addEdge(int x, int y) {
	static int tot = 0;
	edge[++tot].to = y;
	edge[tot].next = head[x], head[x] = tot;
}

void init() {
	must[0] = must[1] = mustnot[0] = mustnot[1] = 0;
	for (int i = 1; i <= n; i++)
		f[i][0] = f[i][1] = INF;
}

void dfs(int x, int fa) {
	int64 f0 = 0, f1 = 0;
	for (int i = head[x]; i; i = edge[i].next) {
		int y = edge[i].to;
		if (y == fa)
			continue;
		dfs(y, x);
		f0 += f[y][1];
		if (f0 > INF - EPS)
			f0 = INF;
		f1 += min(f[y][0], f[y][1]);
		if (f1 > INF - EPS)
			f1 = INF;
	}
	f1 += v[x]; 
	if (x == must[0] || x == must[1]) //必须驻扎 
		f0 = INF; //不驻扎代价为INF 
	if (x == mustnot[0] || x == mustnot[1]) //不得驻扎 
		f1 = INF; //驻扎代价为INF 
	f[x][0] = f0;
	f[x][1] = f1;
}

int main() {
//	freopen("defense.in", "r", stdin);
//	freopen("defense.out", "w", stdout);
	char tmp[3];
	scanf("%d%d%s", &n, &q, tmp);
	for (int i = 1; i <= n; i++)
		scanf("%d", v + i);
	for (int i = 1; i <= n - 1; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		addEdge(x, y), addEdge(y, x);
	}
	for (int i = 1; i <= q; i++) {
		init();
		int a, b, x, y;
		scanf("%d%d%d%d", &a, &x, &b, &y);
		if (x) //a必须驻扎
			must[0] = a;
		else //a不得驻扎 
			mustnot[0] = a;
		if (y)
			must[1] = b;
		else
			mustnot[1] = b;
		dfs(1, 0);
		ans = min(f[1][0], f[1][1]);
		if (ans > INF - EPS)
			puts("-1");
		else
			printf("%lld %d\n", ans, i);
//		for (int i = 1; i <= n; i++)
//			printf("%d ", f[i][0]);
//		puts("");
//		for (int i = 1; i <= n; i++)
//			printf("%d ", f[i][1]);
//		return 0;
	}
	return 0;
} 
