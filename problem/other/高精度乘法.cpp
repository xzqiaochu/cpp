#include <iostream>
#include <cstring>

#define maxn 201

using namespace std;

int main() {
	char a[maxn];
	char b[maxn];
	int r[maxn] = {0};
	cin >> a;
	cin >> b;
	for (int i = strlen(a) - 1, j = 0; i >= 0; i--, j++) {
		r[j] = a[i] - 48;
	}
	for (int i = strlen(b) - 1, j = 0; i >= 0; i--, j++) {
		r[j] *= b[i] - 48;
		if (r[j] >= 10) {
			r[j + 1] += r[j] / 10;
			r[j] %= 10;
		}
	}
	int r_len = strlen(a) + strlen(b);
	for (; r_len >= 0; r_len--) {
		if (r[r_len] != 0) break;
	}
	for (int i = r_len; i >= 0; i--) {
		cout << r[i]; 
	}
	return 0;
}
