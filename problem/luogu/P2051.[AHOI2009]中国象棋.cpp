#include <iostream>

using namespace std;

int n, m, cnt;
char flag[105];

void dfs(int y) {
	if (y <= n) {
		cnt++; //该排放0个
		cnt %= 9999973; 
		for (int i = 1; i <= m; i++) {
			if (flag[i] < 2) { //该位置能放
				cnt++; //该排放1个
				dfs(y + 1);
				cnt %= 9999973;
				flag[i]++; //该列总数记录 
				for (int j = i + 1; j <= m; j++) {
					if (flag[j] < 2) { //该位置能放
						cnt++; //该排放2个
						cnt %= 9999973;
						flag[j]++; //该列总数记录
						dfs(y + 1);
						flag[j]--; //回溯
					}
				}
				flag[i]--; //回溯
			}
		}
	}
}

int main() {
	cin >> n >> m;
	dfs(1);
	cout << cnt;
	return 0;
} 
