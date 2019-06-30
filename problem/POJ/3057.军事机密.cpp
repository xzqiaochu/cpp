#include <bits/stdc++.h>

using namespace std;

int a[30005];

int main() {
	int n, k;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	cin >> k;
	for (int j = 0; j < k; j++) {
		int temp;
		cin >> temp;
		cout << a[temp - 1] << endl;
	}
 	return 0;
}
