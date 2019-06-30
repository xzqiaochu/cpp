#include <iostream>
#include <cstring>
#include <math.h>

#define maxn 100
#define inf 1000

using namespace std;

double f(char bds[], double x);

char x_sign = 0; 

int main() {
	cout.setf(ios::fixed);
	cout.precision(3);
	char bds_input[maxn];
	char * bds1;
	char * bds2;
	cin >> bds_input;
	bds1 = strtok(bds_input, "=#");
	bds2 = strtok(NULL, "=#");
	double x1 = -inf, x2 = inf, xm = 0;
	while(1) {
		double y1 = f(bds1, x1) - f(bds2, x1);
		double y2 = f(bds1, x2) - f(bds2, x2);
		xm = (x1 + x2) / 2;
		if (fabs(x1 - x2) <= 0.0001) break;
		double ym = f(bds1, xm) - f(bds2, xm);
		if (y2 * ym <= 0) {
			x1 = xm;
		}else{
			x2 = xm;
		}
	}
	cout << x_sign << '=' << xm;
	return 0;
}

double f(char bds[], double x) {
	bool sign = true;
	double sum = 0, temp = 0;
	int i = 0;
	if (bds[i] == '-') {
		sign = false;
		i++;
	}
	for (; i <= strlen(bds) - 1; i++) {
		if (bds[i] == '+') {
			sign ? sum += temp : sum -= temp;
			temp = 0;
			sign = true;
			continue;
		}
		if (bds[i] == '-') {
			sign ? sum += temp : sum -= temp;
			temp = 0;
			sign = false;;
			continue;
		}
		if (isalpha(bds[i])) {
			temp == 0 ? temp = x : temp *= x;
			x_sign = bds[i];
		}
		if (bds[i] >= 48 && bds[i] <= 57) {
			temp = temp * 10 + bds[i] - 48;
		}
		if (i == strlen(bds) - 1) {
			sign ? sum += temp : sum -= temp;
		}
	}
	return sum;
}
