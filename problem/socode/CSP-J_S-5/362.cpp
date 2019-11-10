// 362-Í¼Êé¹ÝµÄÑ¡Ö·
// author: xzqiaochu
// status: 70
// time: 2019/11/1
#include <cstdio>
#include <cmath>
#include <algorithm>

const int N = 2e3 + 7;
const int INF = 0x3f3f3f3f;

struct Point {
	int x, y;
} point[N];

int n, tot, ans = INF;
char s[N];

void hard()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			int d = 0;
			for (int k = 1; k <= tot; k++)
				d += abs(i - point[k].x) + abs(j - point[k].y);
			ans = std::min(ans, d);
		}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s);
		for (int j = 0; j < n; j++)
			if (s[j] == '1')
				point[++tot].x = i, point[tot].y = j+1;
	}
	hard();
	printf("%d", ans);
	return 0;
}
