// CSP-J-B ��ռ������
// author: xzqiaochu
// status: WA
// time: 2019/10/26
#include <cstdio>
#include <algorithm>
#include <queue>

using std::priority_queue;

struct Node
{
	int a, t, av; // a���͸�����t��������ʱ�䣬av����ʱ��� 
	bool operator< (const Node &next) const // true: �ѵ�ǰ���·� 
	{
		if (a == next.a)
			return av > next.av;
		else
			return a < next.a;
	}
};

int n, m;
priority_queue<Node> q;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		Node tmp;
		tmp.av = 0;
		scanf("%d%d", &tmp.a, &tmp.t);
		q.push(tmp);
	}
	int ans = 0;
	while (true)
	{
		Node x = q.top();
		q.pop();
		n -= x.a;
		if (n <= 0)
		{
			ans = std::max(ans, x.av + x.t);
			break;
		}
		x.av += x.t * 2;
		q.push(x);
	}
	printf("%d\n", ans);
	return 0;
}
