#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	vector <int> a;
	cin >> n;
	for (int i = 0; i < 2 * n; i++) {
		int temp;
		cin >> temp;
		a.push_back(temp);
	}
	sort(a.begin(), a.end());
	a.erase(a.begin(), a.begin() + 2);
	a.erase(unique(a.begin(), a.end()), a.end());
	for (int i = 0; i < a.size(); i++) cout << a[i] << ' ';
	return 0;
}
