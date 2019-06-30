#include <iostream>
#include <queue>

using namespace std;

int n, m, d, pro[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool map[101][101], v[101][101];

struct xy {
	int x, y, t, s;
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
	st.s = 0;
	q.push(st);
	while (!q.empty()) {
		xy now = q.front();
		if (now.x == m && now.y == n) return now.t;
		q.pop();
		xy next;
		for (int i = 0; i <= 3; i++) {
			next.x = now.x + pro[i][0];
			next.y = now.y + pro[i][1];
			if (judge(next) && map[next.x][next.y] == 1 && v[next.x][next.y] == 0) {
				v[next.x][next.y] = 1;
				next.t = now.t + 1;
				q.push(next);
			}
			if (now.s <= d) {
				for (int j = 2; j <= d - now.s; j++) {
					next.x = now.x + j * pro[i][0];
					next.y = now.y + j * pro[i][1];
					if (judge(next) == false) break;
					if (map[next.x][next.y] == 1 && v[next.x][next.y] == 0) {
						v[next.x][next.y] = 1;
						next.t = now.t + 1;
						next.s = now.s + j;
						q.push(next);
					}
				}
			}
		}
	}
	return -1;
}

int main() {
	//freopen("escape.in", "r", stdin);
	//freopen("escape.out", "w", stdout);
	cin >> m >> n >> d;
	getchar();
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			char temp = getchar();
			if (temp == 'P') map[i][j] = 1;
			else if (temp == 'L') map[i][j] = 0;
		}
		if (i < m) getchar();
	}
//	for (int i = 1; i <= m; i++) {
//		for (int j = 1; j <= n; j++) cout << map[i][j] << ' ';
//		cout << endl;
//	}
	int temp = bfs();
	if (temp == -1) cout << "impossible";
	else cout << temp;
//    if (arrive && s_ans <= d) cout << t_ans;
//    else cout << "impossible ";
	return 0;
}
