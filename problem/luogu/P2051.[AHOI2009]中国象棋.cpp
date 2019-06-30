#include <iostream>

using namespace std;

int n, m, cnt;
char flag[105];

void dfs(int y) {
	if (y <= n) {
		cnt++; //���ŷ�0��
		cnt %= 9999973; 
		for (int i = 1; i <= m; i++) {
			if (flag[i] < 2) { //��λ���ܷ�
				cnt++; //���ŷ�1��
				dfs(y + 1);
				cnt %= 9999973;
				flag[i]++; //����������¼ 
				for (int j = i + 1; j <= m; j++) {
					if (flag[j] < 2) { //��λ���ܷ�
						cnt++; //���ŷ�2��
						cnt %= 9999973;
						flag[j]++; //����������¼
						dfs(y + 1);
						flag[j]--; //����
					}
				}
				flag[i]--; //����
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
