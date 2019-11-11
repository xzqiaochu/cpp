//3-Ñ¡ÐÅ·â
//author: xzqiaochu
//status: std
//time: 2019/11/12
#include <cstdio>
#include <algorithm>
#include <map>
const int N = 307;
struct Node {
	int x, y;
} a[N<<1];
int sum, ans, n;
std::map<int, int> rt;

int getRoot(int x) {
	return rt[x] == x ? x : (rt[x]=getRoot(rt[x]));
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d%d%d", &a[i<<1].x, &a[i<<1].y, &a[i<<1|1].x, &a[i<<1|1].y);
	for (int k = 50; k; k--) {
		for (int i = 1; i <= n; i++) {
			rt[a[i<<1].x] = a[i<<1].x;
			rt[a[i<<1].y] = a[i<<1].y;
			rt[a[i<<1|1].x] = a[i<<1|1].x;
			rt[a[i<<1|1].y] = a[i<<1|1].y;
		}
		sum = 0;
		for (int i = 1; i <= n; i++) {
			int r = rand() & 1;
			int t1 = getRoot(a[i<<1|r].x);
			int t2 = getRoot(a[i<<1|r].y);
			if (t1 != t2) {
				sum++;
				rt[t1] = t2;
				continue;
			}
			t1 = getRoot(a[i<<1|(1-r)].x);
			t2 = getRoot(a[i<<1|(1-r)].y);
			if (t1 != t2) {
				sum++;
				rt[t1] = t2;
				continue;
			}
		}
		ans = std::max(ans, sum);
	}
	printf("%d\n", ans);
	return 0;
}
