#include <bits/stdc++.h>

using namespace std;

int a[200005];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	int temp = a[0], m = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] == temp) {
			m++;
		} else {
			cout << temp << ' ' << m << endl;
			temp = a[i];
			m = 1;
		} 
	}
	cout << temp << ' ' << m << endl;
}
