// A-灵魂捕手约翰(Catch)
// http://www.mfstem.org/contest/62/problem/A
// author: xzqiaochu
// status: AC
// time: 2019/11/1
#include <cstdio>
#include <cstring>
#include <queue>

using std::queue;

const int SZ = 1e5 + 7;
const int INF = 0x3f3f3f3f;

int n, k;
int b[SZ];
queue<int> q;

int judge(int x)
{
	if (x < 0 || x > 1e5)
		return false;
	if (b[x] != INF)
		return false;
	return true;
}

int bfs(int sta, int tar)
{
	q.push(sta);
	memset(b, 0x3f, sizeof(b));
	b[sta] = 0;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		if (x == tar)
			return b[x]; 
		if (judge(x + 1))
			q.push(x + 1), b[x + 1] = b[x] + 1;
		if (judge(x - 1))
			q.push(x - 1), b[x - 1] = b[x] + 1;
		if (judge(x * 2))
			q.push(x * 2), b[x * 2] = b[x] + 1;	
	}
	return -1;
}

int main()
{
	// freopen("catch.in", "r", stdin);
	// freopen("catch.out", "w", stdout); 
	scanf("%d%d", &n, &k);
	printf("%d", bfs(n, k));
	return 0;
}