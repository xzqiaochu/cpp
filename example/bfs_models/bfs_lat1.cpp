//广搜_一维
#include <iostream>
#include <queue>

#define maxn 100001

using namespace std;

bool v[maxn];
int st, tar, s[maxn], pro[方案数] = {方案};

bool judge(int x) {
	if (x >= 边界 && x <= 边界) return true;
	else return false;
}

int bfs() {
	queue <int> q;
	q.push(st);
	while(!q.empty()) {
		int now = q.front();
		if (搜索到解) return s[now];
		q.pop();
		for (int i = 0; i < 方案数; i++) {
			int next = now + pro[i];
			if(judge(next) && v[next] == 0) {
				v[next] = 1;
				q.push(next);
			}
		}
	}
	return -1; //搜索不到解返回值
}

int main() {
	//st,tar
	cout << bfs(); 
	return 0;
}
