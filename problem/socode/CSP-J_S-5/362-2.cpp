// 362-Í¼Êé¹ÝµÄÑ¡Ö·
// author: xzqiaochu
// status: 90
// time: 2019/11/1
#include <cstdio>
#include <cmath>
#include <algorithm>

const int N = 4e7 + 7;
const int INF = 0x3f3f3f3f;

struct Point {
	int x, y;
} point[N];

struct None {
	int x, y;
} none[N];

int n, tot1, tot2, ans = INF;
char s[N];

void hard() {
	for (int i = 1; i <= tot2; i++) {
		int d = 0;
		for (int j = 1; j <= tot1; j++)
			d += abs(none[i].x - point[j].x) + abs(none[i].y - point[j].y);
		ans = std::min(ans, d);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", s);
		for (int j = 0; j < n; j++)
			if (s[j] == '1')
				point[++tot1].x = i, point[tot1].y = j+1;
			else
				none[++tot2].x = i, none[tot2].y = j+1;
	}
	if (tot1 == 0)
	{
		puts("0");
		return 0;
	}
	hard();
	printf("%d", ans);
	return 0;
}
