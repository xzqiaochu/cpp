//2-Â·¾¶Êý
//author: xzqiaochu
//status: std
//time: 2019/11/11
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
const int N = 107, M = 1e9 + 9;
const int dirx[4] = {-1, 1, 0, 0}, diry[4] = {0, 0, -1, 1};

int a[N][N], n, dis[N][N], cnt[N][N];
bool vis[N][N];
struct Node {
	int x, y;
	bool operator< (const Node &b) const {
		return dis[x][y] > dis[b.x][b.y];
	}
};

void Dijkstra() {
	memset(vis, false, sizeof(vis));
	memset(cnt, 0, sizeof(cnt));
	memset(dis, 0x3f, sizeof(dis));
	dis[1][1] = a[1][1], cnt[1][1] = 1;
	std::priority_queue<Node> que;
	que.push(Node{1, 1});
	while (!que.empty()) {
		Node u = que.top();
		que.pop();
		if (vis[u.x][u.y])
			continue;
		vis[u.x][u.y] = true;
		for (int i = 0; i < 4; i++) {
			int x = u.x + dirx[i], y = u.y + diry[i];
			if (x < 1 || y < 1 || x + y > n + 1)
				continue;
			if (dis[x][y] < dis[u.x][u.y] + a[x][y])
				continue;
			if (dis[x][y] == dis[u.x][u.y] + a[x][y])
				cnt[x][y] += cnt[u.x][u.y];
			else {
				dis[x][y] = dis[u.x][u.y] + a[x][y];
				cnt[x][y] = cnt[u.x][u.y];
				que.push(Node{x, y});
			}
		}
	}
}

int main() {
	while (~scanf("%d", &n) && n) {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				scanf("%d", &a[i][j]);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j < n + 1 - i; j++)
				a[i][j] += a[n + 1 -j][n + 1 - i];
		Dijkstra();
		int ans = 0, mi = 2e9;
		for (int i = 1; i <= n; i++) {
			int j = n + 1 - i;
			if (dis[i][j] < mi)
				mi = dis[i][j], ans = cnt[i][j];
			else if (dis[i][j] == mi)
				ans += cnt[i][j]; 
		}
		printf("%d\n", ans % M);
	}
	return 0;
}
