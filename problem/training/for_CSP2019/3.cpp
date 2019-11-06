// ºÚµ•Õº¬€Ã‚ (gr.in/out)
// author: qiaochu(following Liu)
// status: AC 
// time: 2019/11/04
#include <cstdio>
#include <vector>
#include <queue>
const int VSZ = 5007, ESZ = VSZ << 1, QSZ = 1e6 + 7;
const int INF = 0x3f3f3f3f;

int n, m, k;
bool ans[QSZ];

struct Q {
	int x, y, dis;
} q[QSZ];
std::vector<int> t[VSZ];

int head[VSZ];
struct Edge {
	int to, next;
} edge[ESZ];

int dis[2][VSZ];
bool vis[VSZ];

inline void addEdge(int x, int y) {
	static int tot = 0;
	edge[++tot].to = y;
	edge[tot].next = head[x], head[x] = tot;
}

void spfa(int sta) {
	std::queue<int> q;
	for (int i = 1; i <= n; i++)
		dis[0][i] = dis[1][i] = INF, vis[i] = false;
	q.push(sta);
	vis[0] = true;
	dis[0][sta] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		vis[x] = false;
		for (int i = head[x]; i; i = edge[i].next) {
			int y = edge[i].to;
			bool flag = false;
			if (dis[1][y] > dis[0][x] + 1)
				dis[1][y] = dis[0][x] + 1, flag = true;
			if (dis[0][y] > dis[1][x] + 1)
				dis[0][y] = dis[1][x] + 1, flag = true;
			if (flag && !vis[y])
				q.push(y), vis[y] = true;
		}
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		addEdge(x, y), addEdge(y, x);
	}
	for (int i = 1; i <= k; i++) {
		scanf("%d%d%d", &q[i].x, &q[i].y, &q[i].dis);
		t[q[i].x].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		if (t[i].size() == 0)
			continue;
		spfa(i);
		for (int j = 0; j < (int)t[i].size(); j++) {
			int x = t[i][j];
			int num = q[x].dis & 1;
			if (q[x].dis >= dis[num][q[x].y] && head[i])
				ans[x] = true;
		}
	}
	for (int i = 1; i <= k; i++)
		ans[i] ? puts("TAK") : puts("NIE");
	return 0;
}
