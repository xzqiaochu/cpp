// C-赛道修建(track)
// http://www.mfstem.org/contest/28/problem/C
// author: xzqiaochu
// status: AC
// time: xzqiaochu
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
const int NSZ = 5e4 + 7, MSZ = NSZ * 2;

int n, m;

int head[NSZ];
struct Edge {
	int to, w, next;
} edge[MSZ];

int up, k, cnt;
multiset<int> s[NSZ];

inline void addEdge(int x, int y, int z) {
	static int tot = 0;
	edge[++tot].to = y, edge[tot].w = z;
	edge[tot].next = head[x], head[x] = tot;
}

//求树的直径
int dfs1(int x, int fa) {
	int sum1 = 0, sum2 = 0;
	for(int i = head[x]; i; i = edge[i].next) {
		int y = edge[i].to, z = edge[i].w;
		if(y == fa)
			continue;
		sum2 = max(sum2, dfs1(y,x) + z);
		if(sum1 < sum2)
			swap(sum1,sum2);
	}
	up = max(up, sum1 + sum2);
	return sum1;
}

int dfs(int x, int fa) {
	s[x].clear();
	for (int i = head[x]; i; i = edge[i].next) {
		int y = edge[i].to, z = edge[i].w;
		if (y == fa)
			continue;
		int val = dfs(y, x) + z;
		if (val >= k)
			cnt++;
		else
			s[x].insert(val);
	}
	int maxn = 0;
	while (!s[x].empty()) {
		if (s[x].size() == 1)
			return max(maxn, *s[x].begin());
		multiset<int>::iterator it;
		it = s[x].lower_bound(k - *s[x].begin());
		if (it == s[x].begin() && s[x].count(*it) == 1)
			it++;
		if (it == s[x].end()) {
			maxn = max(maxn, *s[x].begin());
			s[x].erase(s[x].begin());
		} else {
			cnt++;
			s[x].erase(it); //先删除后面的元素
			s[x].erase(s[x].begin());
		}
	}
	return maxn;
}

bool check(int x) {
	k = x, cnt = 0;
	dfs(1, 0);
	if (cnt >= m)
		return true;
	else
		return false;
}

int main() {
	// freopen("track.in", "r", stdin);
	// freopen("track.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n - 1; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		addEdge(x, y, z), addEdge(y, x, z);
	}
	dfs1(1, 0); //初始化二分上界
	int low = 1, high = up;
	while (low <= high) {
		int mid = (low + high) >> 1;
		if (check(mid)) // 可行
			low = mid + 1;
		else
			high = mid - 1;
	}
	int ans = high;
	printf("%d", ans);
	return 0;
}