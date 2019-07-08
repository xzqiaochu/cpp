// Problem 2 主仆见证了 Hobo 的离别(friendship)
// author: xzqiaochu
// status: PAC(70% AC)
#include <cstdio>
#include <cstring>
#include <queue>

#define next Next

using namespace std;

const int MAXN = 250007, MAXM = 500007;

int n, m, cnt;
int tot, head[MAXN], ver[MAXM], next[MAXN];
bool v[MAXN];

inline void add(int x, int y)
{
	ver[++tot] = y;
	next[tot] = head[x], head[x] = tot;
} 

void init()
{
	for (int i = 1; i <= cnt; i++)
		v[i] = 0;
}

bool bfs(int sta, int tar)
{
	queue<int> q;
	init();
	v[sta] = true;
	q.push(sta);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		if (x == tar)
			return true;
		for (int i = head[x]; i; i = next[i])
		{
			int y = ver[i];
			if (!v[y])
				q.push(y), v[y] = true; 
		}
	}
	return false;
}

int main()
{
// 	freopen("friendship.in", "r", stdin);
// 	freopen("friendship.out", "w", stdout);
	scanf("%d%d", &n, &m);
	cnt = n;
	while (m--)
	{
		int temp;
		scanf("%d", &temp); 
		if (temp == 0) // 融合
		{
			int op;
			scanf("%d", &op);
			if (op == 0) // 交
			{
				int k;
				scanf("%d", &k);
				int x = ++cnt;
				for (int i = 1; i <= k; i++)
				{
					int y;
					scanf("%d", &y);
					add(x, y);
					if (k == 1)
						add(y, x);
				}
			}
			else // 并
			{
				int k;
				scanf("%d", &k);
				int y = ++cnt;
				for (int i = 1; i <= k; i++)
				{
					int x;
					scanf("%d", &x);
					add(x, y);
					if (k == 1)
						add(y, x);
				}
			}
		}
		else // 询问
		{
			int sta, tar;
			scanf("%d%d", &sta, &tar);
			if (bfs(sta, tar))
				puts("1");
			else
				puts("0"); 
		}
	}
	return 0;
} 