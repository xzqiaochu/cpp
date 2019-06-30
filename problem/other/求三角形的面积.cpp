#include <iostream>
#include <cmath>

using namespace std;

int main() {
	cout.setf(ios::fixed);
	cout.precision(2);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		double a, b, c, q, s;
		cin >> a >> b >> c;
		if ((a + b) > c && (a + c) > b && (b + c) > a) {
			q = (a + b + c) / 2;
			s = sqrt(q * (q - a) * (q - b) * (q - c));
			if (i == n) {
				cout << s;
			} else {
				cout << s << endl;
			}
		} else {
			if (i == n) {
				cout << "NO";
			} else {
				cout << "NO" << endl;
			}
		}
	}
	return 0;
}
