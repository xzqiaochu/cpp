#include <bits/stdc++.h>

//#define cin fin
//#define cout fout

using namespace std;

ifstream fin("window.in");
ofstream fout("window.out");

int a[1000005];
int mins[1000005];
int maxs[1000005];

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	for (int i = 0; i <= n - k; i++) {
		int * window;
		window = new int[k];
		for (int j = 0; j < k; j++) {
			window[j] = a[i + j];
		}
		sort(window, window + k);
		mins[i] = window[0];
		maxs[i] = window[k - 1];
		delete window;
	}
	for (int i = 0; i <= n - k; i++) cout << mins[i] << ' ';
	cout << endl;
	for (int i = 0; i <= n - k; i++) cout << maxs[i] << ' ';
	return 0;
}
