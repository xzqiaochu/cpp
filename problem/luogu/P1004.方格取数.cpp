#include <iostream>

#define maxn 12

using namespace std;

int m[maxn][maxn], p[maxn][maxn][maxn][maxn];
	
int main() {
	int n;
	cin >> n;
	while (1) {
		int a, x, y;
		cin >> x >> y >> a;
		if (a == 0 && x == 0 && y == 0) break;
		m[x][y] = a;
	}
	for (int x1 = 1; x1 <= n; x1++) {
		for (int y1 = 1; y1 <= n; y1++) {
			for (int x2 = 1; x2 <= n; x2++) {
				for (int y2 = 1; y2 <= n; y2++) {
					p[x1][y1][x2][y2] = m[x1][y1] + m[x2][y2] + max(max(p[x1 - 1][y1][x2 - 1][y2], p[x1 - 1][y1][x2][y2 - 1]), max(p[x1][y1 - 1][x2 - 1][y2], p[x1][y1 - 1][x2][y2 - 1]));
					if (x1 == x2 && y1 == y2) p[x1][y1][x2][y2] -= m[x1][y1];
				}
			}
		}
	}
	cout << p[n][n][n][n];
	return 0;
}
