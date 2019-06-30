#include <iostream>

using namespace std;

int main() {
	int l, n, p, minstep = 0, maxstep = 0;
	cin >> l >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p;
		minstep = max(minstep, min(p, l - p + 1));
		maxstep = max(maxstep, max(p, l - p + 1));
	}
	cout << minstep << ' ' << maxstep;
	return 0;
}
