#include <cstdio>
#include <algorithm>

using std::sort;

const int SZN = 407, SZH = 4e4 + 7;

int n;
struct Node
{
	int h, limit, num;
	bool <operator (const Node &b)
	{
		return h < b.limit;
	}
} a[SZN];
bool f[SZH];

void dp()
{
	for (int i = 1; i <= n; i++)
		for (int j = SZH; j >= a[i].limit; j--)
			f[j] = f[j] | f[j - a[i].limit];
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d%d", &a[i].h, &a[i].limit, &a[i].num);
	sort(a + 1, a + n + 1);
	dp();
	return 0;
}
