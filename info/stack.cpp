/* 最大递归层数测试
1e5 8M
2e4 2M
5e6 512M */ 
#include <cstdio>
#include <cstdlib>
#include <algorithm>
const int SZ = 5;

int maxdep = 1e4, step = 1e3;
bool flag;

void dfs(int x, int dep) {
	if (flag)
		return;
	if (dep >= maxdep) {
		printf("%d\n", dep); // 当前递归层数 
		char ch = getchar(); 
		if (ch == 'q') { // 是否结束 
			flag = true;
			return;
		} else {
			maxdep += step;
		}
	}
	int a[SZ];
	for (int i = 0; i <= SZ-1; i++)
		a[i] = i;
	for (int i = 0; i <= SZ-2; i++)
		std::swap(a[i], a[i + 1]);
	dfs(x * 2, dep + 1), dfs(x * 2 + 1, dep + 1);
}

int main() {
	dfs(1, 1);
	return 0;
}