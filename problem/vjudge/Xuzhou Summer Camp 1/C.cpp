// C - Gene Assembly (https://vjudge.net/contest/316356#problem/C)
// auhtor: xzqiaochu
// status: AC
#include <cstdio>
#include <algorithm> 

using std::sort;

const int SZ = 1007;

int n;
struct Node
{
	int st, ed, id;
} a[SZ];

bool cmp(Node a, Node b)
{
	return a.ed < b.ed;
}

int main()
{
	while (1)
	{
		scanf("%d", &n);
		if (n == 0)
			break;
		for (int i = 1; i <= n; i++)
			scanf("%d%d", &a[i].st, &a[i].ed), a[i].id = i;
		sort(a + 1, a + n + 1, cmp);
		int p = 0;
		printf("%d", a[1].id), p = a[1].ed;
		for (int i = 2; i <= n; i++)
		{
			if (a[i].st > p)
				printf(" %d", a[i].id), p = a[i].ed;
		}
		puts("");
	}
	return 0;
}
