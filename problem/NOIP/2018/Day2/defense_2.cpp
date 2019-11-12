// [NOIP2018]Day2-C-保卫王国(defense)
// http://www.mfstem.org/contest/29/problem/C
// author: xzqiaochu
// status: PAC(11/25)
// algorithm: ddp 
// time: 2019/11/11
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using std::min;
typedef long long int64;
const int VSZ = 3e5 + 7, ESZ = VSZ * 2;
const int MAXT = 30;
const int64 INF = 1e18, EPS = 1000;

int n, q;

int v[VSZ]; //点权 
int head[VSZ]; //链式前向星 
struct Edge {
	int to, next;
} edge[ESZ];

int t, dep[VSZ], fa[VSZ][MAXT]; //预处理

bool isnew[VSZ]; //每次询问前需要清空
int must[2], mustnot[2]; //每次询问前需要清空
int64 f0[VSZ][2], f[VSZ][2], bcp[VSZ][2]; //f0每次询问前恢复
int64 ans;

inline void addEdge(int x, int y) {
	static int tot = 0;
	edge[++tot].to = y;
	edge[tot].next = head[x], head[x] = tot;
}

void dfs0(int x) {
	dep[x] = dep[fa[x][0]] + 1;
	for (int i = 1; i <= t; i++)
		fa[x][i] = fa[ fa[x][i-1] ][i-1];
	for (int i = head[x]; i; i = edge[i].next) {
		int y = edge[i].to;
		if (y == fa[x][0])
			return;
		fa[y][0] = x;
		dfs0(y); 
	}
}

int Lca(int x, int y) {
	if (dep[x] < dep[y])
		std::swap(x, y);
	for (int i = t; i >= 0; i--)
		if (dep[ fa[x][i] ] >= dep[y])
			x = fa[x][i];
	if (x == y)
		return x;
	for (int i = t; i >= 0; i--)
		if (fa[x][i] != fa[y][i])
			x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}

void backup() {
	for (int i = 1; i <= n; i++)
		bcp[i][0] = f0[i][0], bcp[i][1] = f0[i][1];
}

void recover() {
	for (int i = 1; i <= n; i++)
		f0[i][0] = bcp[i][0], f0[i][1] = bcp[i][1];
}

void init() {
	must[0] = must[1] = mustnot[0] = mustnot[1] = 0;
	memset(isnew, 0, sizeof(isnew));
}

void dfs1(int x) {
	int64 tmp0 = 0, tmp1 = 0;
	for (int i = head[x]; i; i = edge[i].next) {
		int y = edge[i].to;
		if (y == fa[x][0])
			continue;
		dfs1(y);
		tmp0 += f0[y][1];
		if (tmp0 > INF - EPS)
			tmp0 = INF;
		tmp1 += min(f0[y][0], f0[y][1]);
		if (tmp1 > INF - EPS)
			tmp1 = INF;
	}
	tmp1 += v[x];
	if (x == must[0] || x == must[1]) //必须驻扎 
		tmp0 = INF; //不驻扎代价为INF 
	if (x == mustnot[0] || x == mustnot[1]) //不得驻扎 
		tmp1 = INF; //驻扎代价为INF 
	f0[x][0] = tmp0;
	f0[x][1] = tmp1;
}

void deflag(int x) {
	if (x == 0)
		return;
	isnew[x] = true;
	deflag(fa[x][0]);
}

void dfs2(int x) {
	if (!isnew[x]) {
		f[x][0] = f0[x][0], f[x][1] = f0[x][1];
		return;
	}
	int64 tmp0 = 0, tmp1 = 0;
	for (int i = head[x]; i; i = edge[i].next) {
		int y = edge[i].to;
		if (y == fa[x][0])
			continue;
		dfs2(y);
		tmp0 += f[y][1];
		if (tmp0 > INF - EPS)
			tmp0 = INF;
		tmp1 += min(f[y][0], f[y][1]);
		if (tmp1 > INF - EPS)
			tmp1 = INF;
	}
	tmp1 += v[x]; 
	f[x][0] = tmp0;
	f[x][1] = tmp1;
}

int main() {
//	freopen("defense.in", "r", stdin);
//	freopen("defense.out", "w", stdout);
	char tmp[3]; //无用参数 
	scanf("%d%d%s", &n, &q, tmp);
	for (int i = 1; i <= n; i++)
		scanf("%d", v + i);
	for (int i = 1; i <= n - 1; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		addEdge(x, y), addEdge(y, x);
	}
	t = log2(n) + 1; //倍增求LCA最大二次幂 
	dfs0(1); //初级预处理 
	dfs1(1); //次级预处理 
	for (int i = 1; i <= q; i++) {
		init(); //每次询问前初始化 
		int a, b, x, y, lca;
		scanf("%d%d%d%d", &a, &x, &b, &y);
		if (x) //a必须驻扎
			must[0] = a;
		else //a不得驻扎 
			mustnot[0] = a;
		if (y)
			must[1] = b;
		else
			mustnot[1] = b;
		backup(); //备份f0数组 
		lca = Lca(a, b); //求LCA 
		dfs1(lca); //更新子树 
		deflag(fa[lca][0]); //把需要更新的节点打上标记（即f0不是最优的节点） 
		dfs2(1); //主dfs 
		ans = min(f[1][0], f[1][1]);
		if (ans > INF - EPS)
			puts("-1");
		else
			printf("%lld\n", ans);
		recover(); //恢复f0数组
	}
	return 0;
}
