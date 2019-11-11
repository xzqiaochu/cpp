//2-路径数
//author: xzqiaochu
//status: 已过样例
//time: 2019/11/11
#include <cstdio>
typedef long long int64;
const int SZ = 107;
const int INF = 0x3f3f3f3f;
const int pro[4][2][2] = {
	{{1, 0}, {0, -1}},
	{{-1, 0}, {0, 1}},
	{{0, 1}, {-1, 0}},
	{{0, -1}, {1, 0}}
};

int n, g[SZ][SZ];
int64 minn, cnt;
bool vis[SZ][SZ];

inline bool judge(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= n && !vis[x][y];
}

void dfs(int x1, int y1, int x2, int y2, int64 s) {
	if (s > minn)
		return;
	if (x1 == x2 && y1 == y2) {
		if (s == minn)
			cnt++;
		else
			minn = s, cnt = 1;
		return;
	}
	for (int k = 0; k <= 3; k++) {
		int nx1 = x1 + pro[k][0][0], ny1 = y1 + pro[k][0][1];
		int nx2 = x2 + pro[k][1][0], ny2 = y2 + pro[k][1][1];
		if (judge(nx1, ny1) && judge(nx2, ny2)) {
			int ns = s + g[nx1][ny1] + g[nx2][ny2];
			vis[nx1][ny1] = vis[nx2][ny2] = true;
			dfs(nx1, ny1, nx2, ny2, ns);
			vis[nx1][ny1] = vis[nx2][ny2] = false;
		}
	}
}

int main() {
	while (1) {
		scanf("%d", &n);
		if (n == 0)
			break; 
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				scanf("%d", &g[i][j]);
		minn = INF, cnt = 0;
		vis[1][1] = vis[n][n] = true;
		dfs(1, 1, n, n, 0);
		vis[1][1] = vis[n][n] = false;
		printf("%lld\n", cnt);
	}
	return 0;
}
