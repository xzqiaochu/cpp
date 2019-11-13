//[洛谷P1144]最短路计数
//https://www.luogu.org/problem/P1144
//author: xzqiaochu
//status: AC
//time: 2019/11/13
#include <cstdio>
#include <cstring>
#include <utility>
#include <queue>
using std::priority_queue;
using std::pair;
using std::make_pair;
const int NSZ = 1e6 + 7, MSZ = 2e6 + 7;
const int MOD = 100003;

int n, m;

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

void Dijkstra() {
	memset(dis, 0x3f, sizeof(dis)), dis[1] = 0;
	memset(vis, 0, sizeof(vis));
	memset(pro, 0, sizeof(pro)), pro[1] = 1;
	priority_queue< pair<int, int> > q;
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
			}
			if (dis[x] + z == dis[y])
				pro[y] = (pro[y] + pro[x]) % MOD;
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		addEdge(x, y, 1), addEdge(y, x, 1);
	}
	Dijkstra();
	for (int i = 1; i <= n; i++)
		printf("%d\n", pro[i]);
	return 0;
}
