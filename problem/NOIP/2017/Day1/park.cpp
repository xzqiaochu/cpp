//[NOIP2017]-Day1-逛公园(park)
//http://www.mfstem.org/contest/26/problem/C
//author: xzqiaochu
//status: PAC(3/10)
//algorithm: 拿部分分 k=0的情况 求最短路方案数 
//time: 2019/11/13
#include <cstdio>
#include <utility>
#include <queue>
using std::priority_queue;
using std::pair;
using std::make_pair;
const int NSZ = 1e5 + 7, MSZ = 2e5 + 7;
const int INF = 0x3f3f3f3f;

int n, m, k, MOD;

int tot, head[NSZ];
struct Edge {
	int to, weight, next;
} edge[MSZ];

bool vis[NSZ];
int dis[NSZ], pro[NSZ];

inline void addEdge(int x, int y, int z) {
	edge[++tot].to = y, edge[tot].weight = z;
	edge[tot].next = head[x], head[x] = tot;
}

void init_dij() {
	for (int i = 1; i <= n; i++)
		dis[i] = INF, vis[i] = false, pro[i] = 0;
}

void Dijkstra() {
	init_dij();
	priority_queue< pair<int, int> > q;
	dis[1] = 0, pro[1] = 1;
	q.push(make_pair(0, 1));
	while (!q.empty()) {
		int x = q.top().second;
		q.pop();
		if (vis[x])
			continue;
		vis[x] = true;
		for (int i = head[x]; i; i = edge[i].next) {
			int y = edge[i].to, z = edge[i].weight;
			if (dis[x] + z < dis[y]) {
				dis[y] = dis[x] + z;
				q.push(make_pair(-dis[y], y));
				pro[y] = pro[x]; //最短路径被更新
			} else if (dis[x] + z == dis[y])
				pro[y] = (pro[y] + pro[x]) % MOD;
		}
	}
}

void initT() {
	tot = 0;
	for (int i = 1; i <= n; i++)
		head[i] = 0;
}

int main() {
//	freopen("part.in", "r", stdin);
//	freopen("park.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) {
		initT();
		scanf("%d%d%d%d", &n, &m, &k, &MOD);
		for (int i = 1; i <= m; i++) {
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			addEdge(x, y, z);
		}
		Dijkstra();
		printf("%d\n", pro[n]);
	}
	return 0;
}
