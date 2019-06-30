#include <iostream>
#include <cmath>

using namespace std;

int list[25];

bool is_2k(int a) {
	double k = (log(a) / log(2));
	if ((int)k == k) return true;
	else return false;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) cin >> list[i];
	for (int i = 0; i < t; i++) {
		int n = list[i];
		bool flag = false;
		if (n % 2 == 0) {
			for (int i = 1; pow(2, i) < n; i++) {
				int left = n - pow(2, i);
				if (is_2k(left)) {
					flag = true;
					break;
				}
			}
		}
		if (flag) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}
