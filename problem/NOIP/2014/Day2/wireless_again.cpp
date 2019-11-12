//[NOIP2014]-Day2-A-无线网路发射器选址(wireless)
//http://www.mfstem.org/contest/19/problem/A
//author: xzqiaochu
//status: AC
//algorithm: 暴力枚举即可 
//time: 2019/11/12
#include <cstdio>
#include <algorithm>
const int SZ = 150;

int n, d, g[SZ][SZ];

int getSum(int x1, int y1, int x2, int y2) {
	x1 = std::max(0, x1), x2 = std::min(128, x2);
	y1 = std::max(0, y1), y2 = std::min(128, y2);
	int cnt = 0;
	for (int i = x1; i <= x2; i++)
		for (int j = y1; j <= y2; j++)
			cnt += g[i][j];
	return cnt;
}

int main() {
//	freopen("wireless.in", "r", stdin);
//	freopen("wireless.out", "w", stdout);
	scanf("%d%d", &d, &n);
	for (int i = 1; i <= n; i++) {
		int x, y, k;
		scanf("%d%d%d", &x, &y, &k);
		g[x][y] = k;
	}
	int maxn = 0, cnt = 0;
	for (int i = 0; i <= 128; i++)
		for (int j = 0; j <= 128; j++) {
			int num = getSum(i - d, j - d, i + d, j + d);
			if (num > maxn)
				maxn = num, cnt = 1;
			else if (num == maxn)
				cnt++;
		}
	printf("%d %d", cnt, maxn);
	return 0;
} 
