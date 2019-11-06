// A-旅行(travel)
// http://www.mfstem.org/contest/29/problem/A
// author: xzqiaochu
// status: PAC(22/25) TLE
// time: 2019/11/06 
// algorithm: DFS预处理找环 
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

//init_dfs使用
bool flag, vis[NSZ]; //flag为dfs中断标记 
int pre[NSZ];
int cyc_sta, use_edge[NSZ], cyc[NSZ]; //环所在的编号（id为奇数不变，偶数-1，防止双向边被重复统计） 

//bool flag, vis[NSZ];
int del1, del2, tmp[NSZ], ans[NSZ];
set<int> s[NSZ];

inline void addEdge(int x, int y) {
	static int tot = 0;
	edge[++tot].to = y;
	edge[tot].next = head[x], head[x] = tot;
}

void init_dfs(int x, int fa) {
	if (vis[x]) {
		pre[x] = 0; //环的起点 
		cyc_sta = fa; //环的终点 
		flag = true;
		return; 
	}
	vis[x] = true; //打标记 
	for (int i = head[x]; i; i = edge[i].next) {
		if (flag) //在此处要立即判断中止信号 
			return; //如果下次进入递归再判断，会导致信息被修改 
		int y = edge[i].to;
		if (y == fa)
			continue;
		//记录信息 
		pre[y] = x;
		use_edge[y] = i; 
		init_dfs(y, x);
	}
} 

void init_cyc() {
	int x = cyc_sta;
	while (x) {
		int from_edge;
		if (use_edge[x] % 2 == 0) //id为奇数不变，偶数-1
			from_edge = use_edge[x] - 1;
		else
			from_edge = use_edge[x];
		cyc[++cyc[0]] = from_edge;
		x = pre[x];
	}
}

void dfs(int x, int fa) {
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
		init_dfs(1, 0); //检测环 
		init_cyc();
//		puts("");
//		for (int i = 1; i <= cyc[0]; i++)
//			printf("%d ", cyc[i]);
//		return 0; 
		//逐个删边 
		for (int i = 1; i <= cyc[0]; i++) {
			del1 = cyc[i], del2 = cyc[i] + 1; //删除边标记 
			tmp[0] = 0; //初始化 
			dfs(1, 0);
			update(); 
		}
		for (int i = 1; i <= n; i++)
			printf("%d ", ans[i]);
	}
	return 0;
}
