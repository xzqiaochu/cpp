// D-×î¶ÌÂ·¾¶(shortest)
// http://www.mfstem.org/contest/53/problem/D
// author: xzqiaochu
// status: AC
// time: 2019/10/31
#include <cstdio>
#include <cstring>
#include <utility>
#include <queue>

using std::pair;
using std::make_pair;
using std::priority_queue; 

const int SZ = 16, ESZ = SZ*SZ;
const int INF = 0x3f3f3f3f;

int n;

struct Edge
{
	Edge() {}
	Edge(int _ver, int _weight, int _next) : ver(_ver), weight(_weight), next(_next) {}
	int ver, weight, next;
} edge[ESZ];

int head[SZ];

struct Point
{
	Point() : dis(INF), pre(0) {}
	Point(int _dis, int _pre) : dis(_dis), pre(_pre) {}
	int dis, pre;
} point[SZ];

inline void addEdge(int x, int y, int z)
{
	static int tot;
	edge[++tot] = Edge(y, z, head[x]);
	head[x] = tot;
}

priority_queue< pair<int, int> > q;
bool vis[SZ];

int Dijkstra()
{
	point[1].dis = 0;
	q.push(make_pair(0, 1));
	while (!q.empty())
	{
		int x = q.top().second;
		q.pop();
		if (x == n)
			return point[x].dis;
		if (vis[x])
			continue;
		vis[x] = true;
		for (int i = head[x]; i; i = edge[i].next)
		{
			int y = edge[i].ver, z = edge[i].weight;
			if (point[x].dis + z < point[y].dis)
			{
				point[y].dis = point[x].dis + z;
				point[y].pre = x;
				q.push(make_pair(-point[y].dis, y)); 
			}
		}
	}
	return -1;
}

int out[SZ];

void print()
{
	for (int i = n; i; i = point[i].pre)
		out[++out[0]] = i;
	for (int i = out[0]; i >= 1; i--)
		printf("%d ", out[i]);
}

int main()
{
	scanf("%d", &n);
	int tmp;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &tmp);
			if (tmp)
				addEdge(i, j, tmp);
		}
	int dis = Dijkstra();
	printf("minlong=%d\n", dis);
	print();
	return 0;
}
