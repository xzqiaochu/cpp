// D-吃豆吧(HaveBean)
// http://www.mfstem.org/contest/62/problem/D
// author: xzqiaochu(following kelvin)
// status: AC
// time: 2019/11/1
#include <cstdio>
#include <algorithm>
#include <queue>

const int N = 2007;
const int INF = 0x3f3f3f3f;

struct Node {
	int x, y;
	bool operator< (const Node &b) const {
		return x < b.x || x == b.x && y < b.y;
	}
} nd[N];

struct Edge {
	int u, v, next;
} eg[N<<3];

int head[N], n, in[N], id[N], tpid[N], cnt, f[N][N];
// id[原编号] = 拓扑序
// tipid[拓扑序] = 原编号

inline void addEdge(int u, int v) {
	static int cnt = 0;
	eg[++cnt].next = head[u], head[u] = cnt;
	eg[cnt].u = u, eg[cnt].v = v;
}

void tpSort(int s) {
	std::queue<int> que;
	que.push(s);
	while (!que.empty()) {
		int u = que.front();
		que.pop();
		id[u] = ++cnt, tpid[cnt] = u;
		for (int i = head[u]; i; i = eg[i].next)
			if (--in[eg[i].v] == 0)
				que.push(eg[i].v);
	}
}

void dp(int x, int y) {
	for (int i = head[x]; i; i = eg[i].next) {
		int v = eg[i].v, u = y;
		if (id[v] > id[u])
			std::swap(u, v);
		if (v != u)
			f[v][u] = std::max(f[v][u], f[x][y] + 1);
		else
			f[v][u] = std::max(f[v][u], f[x][y]);
	}
}

int main() {
//	freopen("beanman.in", "r", stdin);
//	freopen("beanman.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &nd[i].x, &nd[i].y);
	std::sort(nd+1, nd+n+1);
	for (int i = 1; i <= n; i++) {
		int ai = INF;
		for (int j = i + 1; j <= n; j++)
			if (nd[i].y <= nd[j].y && nd[j].y < ai)
				ai = nd[j].y, in[j]++, addEdge(i, j);
	}
	int a = 0, t = n+1;
	for (int i = 1; i <= n; i++) {
		addEdge(a, i), in[i]++;
		addEdge(i, t), in[t]++;
	}
	tpSort(a);
	for (int i = 1; i <= cnt; i++)
		for (int j = i; j <= cnt; j++)
			dp(tpid[i], tpid[j]);
	printf("%d\n", f[t][t] - 1);
}