#include <iostream> 

using namespace std;

bool map[10][10], visit[10][10], found;
int m, n;

bool judge(int x, int y) {
	if (x >= 0 && x < m && y >= 0 && y < n && map[x][y] == 1 && visit[x][y] == 0) return true;
	else return false;
}

void dfs(int x, int y) {
	if (found) return;
	if (x == m - 1 && y == n - 1) {
		found = true;
		return;
	}
	if (judge(x + 1, y)) {
		visit[x + 1][y] = 1;
		dfs(x + 1, y);
		visit[x + 1][y] = 0;
	}
	if (judge(x - 1, y)) {
		visit[x - 1][y] = 1;
		dfs(x - 1, y);
		visit[x - 1][y] = 0;
	}
	if (judge(x, y + 1)) {
		visit[x][y + 1] = 1;
		dfs(x, y + 1);
		visit[x][y + 1] = 0;
	}
	if (judge(x, y - 1)) {
		visit[x][y - 1] = 1;
		dfs(x, y - 1);
		visit[x][y - 1] = 0;
	}
}

int main() {
	m = 3;
	n = 4;
	map = {{1,1,1},
	       {1,1,1},
	       {1,1,1},
	       {1,1,1}};
	dfs(0, 0);
	cout << found;
	return 0; 
} 
