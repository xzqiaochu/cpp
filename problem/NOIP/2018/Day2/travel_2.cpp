// A-旅行(travel)
// http://www.mfstem.org/contest/29/problem/A
// author: xzqiaochu
// status: PAC(22/25) TLE
// time: 2019/11/03
// algorithm: 暴力删边 
// notice: 判断一下环所在的边号，枚举删除这些边，便可AC 
#include <cstdio>
#include <cstring>
#include <set>
using std::set; 
const int NSZ = 5007, MSZ = NSZ * 2;

int n, m;

int head[NSZ];
struct Edge {
	int to, next;
} edge[MSZ];

bool flag, vis[NSZ];
int del1, del2, tmp[NSZ], ans[NSZ];
set<int> s[NSZ];

inline void addEdge(int x, int y) {
	static int tot = 0;
	edge[++tot].to = y;
	edge[tot].next = head[x], head[x] = tot;
}

void dfs(int x, int fa) {
	if (flag) //中断标记
		return;
	if (vis[x]) {
		flag = true; //存在环
		return;
	}
	vis[x] = true; //防止出现环 
	tmp[++tmp[0]] = x;
	s[x].clear();
	for (int i = head[x]; i; i = edge[i].next) {
		int y = edge[i].to;
		if (y == fa || i == del1 || i == del2)
			continue;
		s[x].insert(y);
	}
	if (s[x].empty())
		return;
	set<int>::iterator it; //不可以在全局声明，不然会被孩子修改
	for (it = s[x].begin(); it != s[x].end(); it++)
		dfs(*it, x);
}

bool can() {
	if (ans[1] == 0) //第一次 
		return true;
	for (int i = 1; i <= n; i++)
		if (ans[i] != tmp[i])
			return tmp[i] < ans[i];
	return false;
} 

void update() {
	if (can())
		for (int i = 1; i <= n; i++)
			ans[i] = tmp[i];
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
	if (m == n - 1) {
		dfs(1, 0);
		for (int i = 1; i <= n; i++)
			printf("%d ", tmp[i]);
	} else {
		//暴力删边
		for (int i = 1; i <= m; i++) {
			del1 = 2 * i - 1, del2 = 2 * i; //删除边标记 
			memset(vis, 0, sizeof(vis)); //用于判断环 
			flag = false, tmp[0] = 0; //flag为dfs中断标记 
			dfs(1, 0);
			if (flag == false && tmp[0] == n) //dfs正常结束 并且 树是连通的
				update(); 
		}
		for (int i = 1; i <= n; i++)
			printf("%d ", ans[i]);
	}
	return 0;
}
