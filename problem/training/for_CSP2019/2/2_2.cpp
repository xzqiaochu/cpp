//2-路径数
//author: xzqiaochu
//status: dev
//time: 2019/11/11
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;
typedef long long int64;
const int SZ = 107, VSZ = SZ * SZ;
const int MOD = 1000000009, INF = 0x3f3f3f3f;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int n, g[SZ][SZ];
bool vis[VSZ];
int dis[VSZ];
int64 pro[VSZ];

inline int getID(int x, int y) {
	return (x - 1) * n + y;
}

inline int getX(int id) {
	return id / n + 1;
}

inline int getY(int id) {
	return id % n;
}

inline bool judge(int x, int y) {
	return x >= 1 && y >= 1 && x + y <= n + 1;
}

void Dijkstra() {
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	memset(pro, 0, sizeof(pro));
	priority_queue< pair<int, int> > q;
	int sid = getID(1, 1);
	q.push(make_pair(0, sid));
	dis[sid] = g[1][1];
	pro[sid] = 1;
	while (!q.empty()) {
		int uid, x, y;
		uid = q.top().second;
		q.pop();
		if (vis[uid])
			continue;
		vis[uid] = true;
		x = getX(uid), y = getY(uid);
		for (int k = 0; k <= 3; k++) {
			int nx = x + dx[k], ny = y + dy[k];
			int vid = getID(nx, ny);
			if (!judge(nx, ny))
				continue;
			if (dis[vid] > dis[uid] + 1) {
				dis[vid] = dis[uid] + 1;
				q.push(make_pair(-dis[vid], vid));
			}
			//方案数统计 
			if (dis[vid] == dis[uid] + 1) 
				pro[vid] = (pro[vid] + pro[uid]) % MOD;
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &g[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n - i; j++)
			g[i][j] += g[n + 1 - j][n + 1 - i];
	Dijkstra();
	int minn = INF, ans = 0;
	for (int i = 1; i <= n; i++) {
		int j = n + 1 - i;
		int id = getID(i, j);
		minn = min(minn, dis[id]);
	}
	for (int i = 1; i <= n; i++) {
		int j = n + 1 - i;
		int id = getID(i, j);
		if (dis[id] == minn)
			ans += pro[id];
	}
	printf("%d", ans);
	return 0;
}
