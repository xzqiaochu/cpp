#include <iostream>

using namespace std;

int list[5005];

int main() {
	int m, n;
	cin >> m >> n;
	list[1] = 1;
	list[2] = 2;
	for (int i = 3; i <= n - m; i++) {
		list[i] = list[i - 1] + list[i - 2];
	}
	cout << list[n - m];
	return 0;
}
