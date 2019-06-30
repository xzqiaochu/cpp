#include <bits/stdc++.h>

using namespace std;

int a[10005];

int main() {
	int n, b;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> b >> a[i];
	int now = 0;
	while (1) {
		int acc = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] > now) acc++;
		}
		if (acc > n / 2) now++;
		else break;
	}
	int r = 0;
	for (int i = 1; i <= n; i++) r += abs(now - a[i]);
	cout << r;
}
