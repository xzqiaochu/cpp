#include <iostream>
#include <cstring>

#define maxn 201

using namespace std;

char * accAdd(char a[], char b[]);

int main() {
	char a[maxn];
	char b[maxn];
	int r[maxn] = {0};
	cin >> a;
	cin >> b;
	cout << accAdd(a, b);
	return 0;
}

char * accAdd(char a[], char b[]) {
	int c[max(strlen(a), strlen(b)) + 1] = {0};
	for (int i = strlen(a) - 1, j = 0; i >= 0; i--, j++) {
		c[j] = a[i] - 48;
	}
	for (int i = strlen(b) - 1, j = 0; i >= 0; i--, j++) {
		c[j] += b[i] - 48;
		if (c[j] >= 10) {
			c[j] -= 10;
			c[j + 1] += 1;
		}
	}
	int end = max(strlen(a), strlen(b));
	if (c[end] == 0) end -= 1;
	char * r = new char[end];
	memset(r, 0, end);
	for (int i = end, j = 0; i >= 0; i--, j++) {
		r[j] = c[i] + 48;
	}
	return r;
}
