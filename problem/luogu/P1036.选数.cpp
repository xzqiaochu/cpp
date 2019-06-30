#include <iostream>

#define maxn 25

using namespace std;

int n, k, list[maxn], r;

bool is_prime(int n) {
	if (n < 2 || n > 3 && n % 2 == 0) return false;
	for (int i = 3; i * i <= n; i += 2) {
		if (n % i == 0) return false;
	}
	return true;
}

void dfs(int now, int cnt, int s) {
	if (now == n) {
		if (cnt == k && is_prime(s)) r++;
		return;
	}
	dfs(now + 1, cnt, s);
	dfs(now + 1, cnt + 1, s + list[now]);
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> list[i];
	}
	dfs(0, 0, 0);
	cout << r;
	return 0;
}
