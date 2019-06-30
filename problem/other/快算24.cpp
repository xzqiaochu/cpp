#include <iostream>

using namespace std;

double f(int g, double a, double b);

int main() {
	double a, b, c, d, t;
	bool flag = false;
	cin >> a >> b >> c >> d;
	char g[5] = {' ', '+', '-', '*', '/'};
	for (int i = 1; i <= 4; i++) {
		t = f(i, a, b);
		for (int j = 1; j <= 4; j++) {
			t = f(j, t, c);
			for (int k = 1; k <= 4; k++) {
				t = f(k, t, d);
				if (t == 24) {
					flag = true;
					cout << a << g[i] << b << g[j] << c << g[k] << d << endl;
				}
			}
		}
	}
	if (flag == false) cout << "No answer!";
	return 0;
}

double f(int g, double a, double b) {
	switch (g) {
		case 1 : return a + b; break;
		case 2 : return a - b; break;
		case 3 : return a * b; break;
		case 4 : return a / b; break;
	}
}
