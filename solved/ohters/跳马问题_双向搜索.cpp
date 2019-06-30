#include <iostream>
#include <queue>

using namespace std;

char v[1001][1001];
int m, n, s[1001][1001], pro[8][2] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

struct xy {
	int x, y;
};

bool judge(xy next) {
	if (next.x >= 1 && next.x <= m && next.y >= 1 && next.y <= n) return true;
	else return false;
}

int bfs() {
	queue <xy> qa, qb;
	xy st, ed;
	st.x = 1;
	st.y = 1;
	qa.push(st);
	ed.x = m;
	ed.y = n;
	qb.push(ed);
	while(!qa.empty() || !qb.empty()) {
		if (!qa.empty()) {
			xy now = qa.front();
			qa.pop();
			xy next;
			for (int i = 0; i < 8; i++) {
				next.x = now.x + pro[i][0];
				next.y = now.y + pro[i][1];
				if(judge(next)) {
					if (v[next.x][next.y] == 2) {
						return s[now.x][now.y] + s[next.x][next.y] + 1;
					}
					if (v[next.x][next.y] == 0) {
						v[next.x][next.y] = 1;
					    s[next.x][next.y] = s[now.x][now.y] + 1;
					    qa.push(next);
					}
				}
			}
		}
		if (!qb.empty()) {
			xy now = qb.front();
			qb.pop();
			xy next;
			for (int i = 0; i < 8; i++) {
				next.x = now.x + pro[i][0];
				next.y = now.y + pro[i][1];
				if(judge(next)) {
					if (v[next.x][next.y] == 1) {
						return s[now.x][now.y] + s[next.x][next.y] + 1;
					}
					if (v[next.x][next.y] == 0) {
						v[next.x][next.y] = 2;
					    s[next.x][next.y] = s[now.x][now.y] + 1;
					    qb.push(next);
					}
				}
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
