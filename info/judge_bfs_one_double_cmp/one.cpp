#include <iostream>
#include <queue>

using namespace std;

bool v[10001][10001];
int m, n, pro[8][2] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

struct xy {
	int x, y, t;
};

bool judge(xy next) {
	if (next.x >= 1 && next.x <= m && next.y >= 1 && next.y <= n) return true;
	else return false;
}

int bfs() {
	queue <xy> q;
	xy st;
	st.x = 1;
	st.y = 1;
	st.t = 0;
	q.push(st);
	while(!q.empty()) {
		xy now = q.front();
		if (now.x == m && now.y == n) return now.t;
		q.pop();
		xy next;
		for (int i = 0; i < 8; i++) {
			next.x = now.x + pro[i][0];
			next.y = now.y + pro[i][1];
			if(judge(next) && v[next.x][next.y] == 0) {
				v[next.x][next.y] = 1;
				next.t = now.t + 1;
				q.push(next);
			}
		}
	}
	return -1;
}

int main() {
	cin >> m >> n;
	cout << bfs();
	return 0;
}
