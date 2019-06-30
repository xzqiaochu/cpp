#include <iostream>
#include <cmath>

using namespace std;

char map[37][41];

int f(double x) {
	int y = round(cos(x) * 20);
	return y;
}

int main() {
	for (int i = 0; i <= 40; i++) {
		double x = (double) i / 40 * 3.14 * 2;
		int y = f(x);
		map[y + 20][i] = '*';
	}
	for (int i = 0; i <= 36; i++) {
		for (int j = 0; j <= 40; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
	return 0;
}
