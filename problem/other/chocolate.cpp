#include <iostream>

using namespace std;

int n, m, k, a[25][25];

void dfs() {
	
}

int main() {
	int mmin = 0x3f3f3f3f, mmax = 0, sum = 0;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int temp;
			cin >> temp;
			sum += temp;
			mmin = min(mmin, temp);
			mmax = max(mmax, temp);
			a[i][j] = temp;
			
		}
	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) cout << a[i][j] << ' ';
//		cout << endl;
//	}
//    cout << mmin << ' ' << mmax << ' ' << sum;
    for (int i = 1; i <= sum; i++) {
    	if (sum % i == 0) {
    		int temp = sum / i;
    		if (temp >= mmin && temp <= mmax / 2) {
    			cout << temp << ' ';
			}
		}
	}
	return 0;
}
