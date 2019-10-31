//广搜_二维
#include <iostream>
#include <queue>

#define maxn 100001

using namespace std;

bool v[maxn][maxn];
int st_x, st_y, tar_x, tar_y, pro[方案数][2] = {方案};

struct xy {
	int x, y, t;
};

bool judge(xy next) {
	if (next.x >= 边界 && next.x <= 边界 && next.y >= 边界 && next.y <= 边界) return true;
	else return false;
}

int bfs() {
	queue <xy> q;
	xy st;
	st.x = st_x;
	st.y = st_y;
	st.t = 0;
	q.push(st);
	while(!q.empty()) {
		xy now = q.front();
		if (now.x == tar_x && now.y == tar_y) return now.t;
		q.pop();
		xy next;
		for (int i = 0; i < 方案数; i++) {
			next.x = now.x + pro[i][0];
			next.y = now.y + pro[i][1];
			if(judge(next) && v[next.x][next.y] == 0) {
				v[next.x][next.y] = 1;
				next.t = now.t + 1;
				q.push(next);
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
