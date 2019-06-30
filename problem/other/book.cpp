#include <iostream>
#include <map>

using namespace std;

map <int, bool> flag;

int n, cnt, arr[11][101];

void dfs(int now) {
	if (now == n) {
		for (int i = 1; i <= arr[now][0]; i++) {
			if (flag[arr[now][i]] == 0) {
				cnt++;
				cnt %= 1000000007;
			}
	    }
	}
	if (now < n) {
		for (int i = 1; i <= arr[now][0]; i++) {
			if (flag[arr[now][i]] == 0) {
				flag[arr[now][i]] = 1;
				dfs(now + 1);
				flag[arr[now][i]] = 0;
			}
	    }
	}
}

int main() {
	int t;
	cin >> t;
	for (int k = 1; k <= t; k++) {
	cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int j = 1;
		int temp;
	    while(cin >> temp) {
    	    arr[i][j++] = temp;
    	    char c = getchar(); 
    	    if(c == '\n') break;
        }
        arr[i][0] = j - 1;
	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= arr[i][0]; j++) cout << arr[i][j] << ' ';
//		cout << endl;
//	}
	dfs(1);
	cout << cnt << endl;
}
	return 0;
}
