// B - Schedule  (https://vjudge.net/contest/316356#problem/B)
// auhtor: xzqiaochu
// status: WA
#include <cstdio>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

const int SZ = 1e5 + 7;

int n;
struct Node
{
	int s, e;
} a[SZ];
int cnt, sum;
priority_queue< pair<int, int> > q;
// 第一维：终止时间的相反数，第二维：开始时间 

bool cmp(Node a, Node b)
{
	return (a.s < b.s || (a.s == b.s && a.e < b.e));
}

void calc()
{
	q.push(make_pair(-a[1].e, a[1].s));
	for (int i = 2; i <= n; i++)
	{
		pair<int, int> earliest = q.top();
		if (-earliest.first <= a[i].s) // 不需要新机器 
			q.pop(), q.push(make_pair(-a[i].e, earliest.second));
		else // 需要新机器 
			q.push(make_pair(-a[i].e, a[i].s));
	}
	cnt = q.size();
	sum = 0;
	while (!q.empty())
	{
		pair<int, int> now = q.top();
		q.pop();
		sum += -now.first - now.second;
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d%d", &a[i].s, &a[i].e);
		sort(a + 1, a + n + 1, cmp);
		calc();
		printf("%d %d\n", cnt, sum);
	}
	return 0;
}
