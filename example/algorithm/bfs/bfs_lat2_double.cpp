//广搜_二维_双向
#include <iostream>
#include <queue>

#define maxn 100001

using namespace std;

char v[maxn][maxn];
int st_x, st_y, tar_x, tar_y, s[maxn][maxn], pro[方案数][2] = {方案};

struct xy {
	int x, y;
};

bool judge(xy next) {
	if (next.x >= 边界 && next.x <= 边界 && next.y >= 边界 && next.y <= 边界) return true;
	else return false;
}

int bfs() {
	queue <xy> qa, qb;
	xy st, ed;
	st.x = st_x;
	st.y = st_y;
	qa.push(st);
	ed.x = tar_x;
	ed.y = tar_y;
	qb.push(ed);
	while(!qa.empty() || !qb.empty()) {
		if (!qa.empty()) {
			xy now = qa.front();
			qa.pop();
			xy next;
			for (int i = 0; i < 方案数; i++) {
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
			for (int i = 0; i < 方案数; i++) {
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
	return -1; //搜索不到解返回值
}

int main() {
	//st_x,st_y,tar_x,tar_y 
	cout << bfs();
	return 0;
}
