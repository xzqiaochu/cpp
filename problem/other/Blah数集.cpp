#include <iostream>

#define maxn 55

using namespace std;

int blah[maxn], a[maxn], b[maxn];

int main() {
	int a, n;
	cin >> a >> n;
	int two = 1, three = 1, q[maxn];
	q[1] = a;
	for (int i = 1; i <= n; i++) {
		if (2 * q[two] + 1 == 3 * q[three] + 1) {
			q[i] = 2 * q[two] + 1;
			two++, three++;
		}else if (2 * q[two] + 1 < 3 * q[three] + 1) {
			q[i] = 2 * q[two] + 1;
			two++;
		}else if (2 * q[two] + 1 > 3 * q[three] + 1) {
			q[i] = 3 * q[three] + 1;
			three++;
		}
	}
	for (int i = 1; i <= n; i++) cout << q[i] << ' ';
	return 0;
}
