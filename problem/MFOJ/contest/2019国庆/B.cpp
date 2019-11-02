// B-约翰(FJ)的市政工程(grading)
// http://www.mfstem.org/contest/62/problem/B
// author: xzqiaochu
// status: AC
// time: 2019/11/1
#include <cstdio>
#include <algorithm>
#include <queue>

using std::priority_queue;
using std::min;

const int SZ = 2007;

int n, a[SZ];
int ans1, ans2;
priority_queue<int> q1;
priority_queue<int> q2;

void calc1()
{
	for (int i = 1; i <= n; i++)
	{
		q1.push(a[i]);
		if (a[i] < q1.top())
		{
			ans1 += q1.top() - a[i];
			q1.pop();
			q1.push(a[i]);
		}
	}
}

void calc2()
{
	for (int i = 1; i <= n; i++)
	{
		q2.push(-a[i]);
		if (a[i] > -q2.top())
		{
			ans2 += a[i] - (-q2.top());
			q2.pop();
			q2.push(-a[i]);
		}
	}
}

int main()
{
 	// freopen("grading.in", "r", stdin);
 	// freopen("grading.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	calc1();
	printf("%d", ans1);
	return 0;
}