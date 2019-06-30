#include <iostream>

using namespace std;

int main() {
	int a, t, maxdis = 0;
	cin >> a >> t;
	for (int i = 1; i <= t; i++) {
		int temp;
		temp = (a + 5 * i) * (t - i);
		maxdis = max(maxdis, temp);
	}
	cout << maxdis;
	return 0;
}
