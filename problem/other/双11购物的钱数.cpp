#include <iostream>

using namespace std;

int main() {
	cout.setf(ios::fixed);
	cout.precision(2);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int ans = 0;
		for (int j = 1; j <= 11; j++) {
			int temp;
			cin >> temp;
			ans += temp;
		}
		cout << (double) ans / 2 << endl;
	}
	return 0;
}
