#include <bits/stdc++.h>

using namespace std;

int n[100005], ans = 0;
vector <int> fi;

void search(int total, int now = fi.size() - 1, int s = 0) {
	if (total == s) ans++;
	if (s < total && now >= 1) {
		search(total, now - 1, s);
		search(total, now - 1, s + fi[now]);
	}
}

void build(int maxn) {
	fi.push_back(1);
	fi.push_back(1);
	int next = 2;
	while (next <= maxn) {
		fi.push_back(next);
		next = fi[fi.size() - 1] + fi[fi.size() - 2];
	}
}

int main() {
	long long t;
	int maxn = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int temp;
		cin >> temp;
		maxn = max(maxn, temp);
		n[i] = temp;
	}
	build(maxn);
	for (int i = 0; i < t; i++) {
		ans = 0;
		int j = fi.size() - 1;
		while(fi[j] >= n[i]) j--;
		j++;
		search(n[i], j);
		cout << ans << endl;
	}
	return 0;
}
