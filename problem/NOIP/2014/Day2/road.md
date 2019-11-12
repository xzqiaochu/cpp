# [NOIP2014]寻找道路(road)

传送门：[洛谷P2296](https://www.luogu.org/problem/P2296) | [MFOJ](http://www.mfstem.org/contest/19/problem/B)
作者：xzqiaochu

## Solution

一道没有背景的题目......

这是一道最短路的变式题，要先要排除一些非法的点。

![http://static.xzzhangqiaochu.top/images/road.png](http://static.xzzhangqiaochu.top/images/road.png)

如上图所示，我们考虑建立反向边，从终点向起点跑一遍最短路算法（其实BFS就行）。
绿色叉叉的两个点无法被访问，说明这两个点无法通向终点。如果存在一个点指向他们，那么这个点是非法的。（即图中蓝色叉叉的点是非法的）

去除非法的点后，再跑一遍最短路算法就可以啦~

## Code

```cpp
//[NOIP2014]-Day2-B-寻找道路(road)
//http://www.mfstem.org/contest/19/problem/A
//author: xzqiaochu
//status: AC
//algorithm: 通过反向边删除非法的点 
//time: 2019/11/12
#include <cstdio>
#include <cstring> 
#include <utility>
#include <queue>
using std::priority_queue;
using std::pair;
using std::make_pair; 
const int VSZ = 1e4 + 7, MSZ = 2e5 + 7;
const int INF = 0x3f3f3f3f, EPS = 100;

int n, m, s, t;

int tot, head[VSZ];
struct Edge {
	int x, y, next;
} edge[MSZ];

int dis[VSZ];
bool vis[VSZ], not_use[VSZ];

inline void addEdge(int x, int y) {
	edge[++tot].x = x, edge[tot].y = y;
	edge[tot].next = head[x], head[x] = tot;
}

void Dijkstra(int sta, int tar) {
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	priority_queue< pair<int, int> > q;
	dis[sta] = 0;
	q.push(make_pair(0, sta));
	while (!q.empty()) {
		int x = q.top().second; q.pop();
		if (vis[x])
			continue;
		vis[x] = true;
		for (int i = head[x]; i; i = edge[i].next) {
			int y = edge[i].y;
			if (!not_use[y] && dis[x] + 1 < dis[y]) {
				dis[y] = dis[x] + 1;
				q.push(make_pair(-dis[y], y));
			}
		}
	}
}

int main() {
//	freopen("road.in", "r", stdin);
//	freopen("road.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		addEdge(y, x); //添加反向边
	}
	scanf("%d%d", &s, &t);

	Dijkstra(t, s);

	memset(head, 0, sizeof(head)), tot = 0; //清空链式前向星，重新建图
	for (int i = 1; i <= m; i++) {
		if (vis[edge[i].x] == false) //反向边终点未被访问 => 边i未被访问 =>
			not_use[edge[i].y] = true; //（在正向图中）边i无法通向终点 => 该边的起点是非法的 
		addEdge(edge[i].y, edge[i].x); //一个for循环就可以
	}

	Dijkstra(s, t);
	if (dis[t] > INF - EPS)
		printf("-1");
	else
		printf("%d", dis[t]);
	return 0;
}
```
