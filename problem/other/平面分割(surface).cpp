#include <iostream>

using namespace std;

int main() {
	int n, p, cnt;
	cin >> n >> p;
	cnt = 2 * p;
	cnt += (n + p + 2) * (n - p) / 2;
	cout << cnt;
	return 0;
}
