# [NOIP2018] 旅行(travel)

传送门；[洛谷P5022](https://www.luogu.org/problem/P5022) | [MFOJ](http://www.mfstem.org/contest/29/problem/A)
作者：xzqiaochu

---

## Solution

分两种情况

- M = N - 1

这是一棵树，贪心跑一遍DFS序即可。
有一点需要注意的是，要先预处理孩子节点排序，不然会最后三个点会超时。

- M = N

这是一棵基数树。
可以直接暴力删边，时间复杂度 $O(N^2)$，大约 $900ms$ 通过最后三个点（洛谷上测试的）。
正解的话，当然是先预处理出环所在的边。

## Code

```cpp
// A-旅行(travel)
// http://www.mfstem.org/contest/29/problem/A
// author: xzqiaochu
// status: AC
// time: 2019/11/06  
// algorithm: 预处理每个节点的孩子排序 
#include <cstdio>
#include <cstring>
#include <algorithm> 
#include <vector> 
using std::sort;
using std::vector; 
const int NSZ = 5007, MSZ = NSZ * 2;

int n, m;

int head[NSZ];
struct Edge {
	int from, to, next;
} edge[MSZ]; //预处理用 
vector<int> g[NSZ]; //正式处理用 

//init_dfs使用
bool flag, vis[NSZ]; //flag为dfs中断标记 
int pre[NSZ];
int cyc_sta, use_edge[NSZ], cyc[NSZ]; //环所在的编号（id为奇数不变，偶数-1，防止双向边被重复统计） 

//bool flag, vis[NSZ];
int del_x, del_y, tmp[NSZ], ans[NSZ];

inline void addEdge(int x, int y) {
	static int tot = 0;
	edge[++tot].to = y, edge[tot].from = x;
	edge[tot].next = head[x], head[x] = tot;
	g[x].push_back(y);
}

void init_sort() {
	for (int i = 1; i <= n; i++)
		sort(g[i].begin(), g[i].end());
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
	for (unsigned i = 0; i < g[x].size(); i++) {
		int y = g[x][i];
		if (y == fa)
			continue;
		if ((x == del_x && y == del_y) || (x == del_y && y == del_x))
			continue;
		dfs(y, x);
	}
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
	init_sort();
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
		for (int i = 1; i <= cyc[0]; i++) { //枚举环上面的边号 
			int eid = cyc[i];
			del_x = edge[eid].from, del_y = edge[eid].to; //删除边标记 
			tmp[0] = 0; //初始化 
			dfs(1, 0);
			update(); 
		}
		for (int i = 1; i <= n; i++)
			printf("%d ", ans[i]);
	}
	return 0;
}
```
