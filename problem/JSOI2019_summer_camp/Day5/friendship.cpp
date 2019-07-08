// Problem 2 主仆见证了 Hobo 的离别(friendship)
// author: xzqiaochu
// status: dev
#include <cstdio>
#include <cstring>
#include <queue>

#define next Next

using namespace std;

const int MAXQ = 250007, MAXN = 2 * MAXQ, MAXM = 2 * MAXN;

int n, m, cnt;
int tot, head[MAXN], ver[MAXM], next[MAXN];
bool edge[MAXM]; // 交=0, 并=1
int qx[MAXQ], qy[MAXQ];

inline void add(int x, int y, bool z)
{
	ver[++tot] = y, edge[tot] = z; 
	next[tot] = head[x], head[x] = tot;
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
			if (op == 0) // 交=0
			{
				int k;
				scanf("%d", &k);
				int x = ++cnt;
				for (int i = 1; i <= k; i++)
				{
					int y;
					scanf("%d", &y);
					add(x, y, 0);
                    add(y, x, 1);
					// if (k == 1)
				}
			}
			else // 并=1
			{
				int k;
				scanf("%d", &k);
				int y = ++cnt;
				for (int i = 1; i <= k; i++)
				{
					int x;
					scanf("%d", &x);
					add(x, y, 1);
                    add(y, x, 1);
					// if (k == 1)
				}
			}
		}
		else // 询问
			scanf("%d%d", &qx[++qa[0]], &qy[++qb[0]]);
	}
	return 0;
} 