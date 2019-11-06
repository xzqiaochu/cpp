// A-旅行(travel)
// http://www.mfstem.org/contest/29/problem/A
// author: xzqiaochu
// status: PAC(15/25) RE&TLE 
// time: 2019/11/03
// algorithm: 树的DFS序（60分程序） 
#include <cstdio>
#include <set>
using std::set; 
const int NSZ = 5007, MSZ = NSZ * 2;

int n, m, ans[NSZ];

int head[NSZ];
struct Edge {
	int to, next;
} edge[MSZ];

set<int> s[NSZ];

inline void addEdge(int x, int y) {
	static int tot = 0;
	edge[++tot].to = y;
	edge[tot].next = head[x], head[x] = tot;
}

void dfs(int x, int fa) {
	ans[++ans[0]] = x;
	s[x].clear();
	for (int i = head[x]; i; i = edge[i].next) {
		int y = edge[i].to;
		if (y == fa)
			continue;
		s[x].insert(y);
	}
	if (s[x].empty())
		return;
	set<int>::iterator it; //不可以在全局声明，不然会被孩子修改 
	for (it = s[x].begin(); it != s[x].end(); it++)
		dfs(*it, x);
}

int main() {
//	freopen("travel.in", "r", stdin);
//	freopen("travel.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		addEdge(x, y), addEdge(y, x);
	}
	dfs(1, 0);
	for (int i = 1; i <= ans[0]; i++)
		printf("%d ", ans[i]);
	return 0;
}