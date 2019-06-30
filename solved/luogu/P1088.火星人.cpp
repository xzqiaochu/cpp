#include <bits/stdc++.h>

#define maxn 10005

using namespace std;

int main() {
	int n, m, list[maxn];
	cin >> n >> m;
	for (int i = 0; i <= n - 1; i++) cin >> list[i];
	for (int i = 1; i <= m; i++) next_permutation(list, list + n);
	for (int i = 0; i <= n - 1; i++) cout << list[i] << ' ';
	return 0;
}
