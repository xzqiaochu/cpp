#include <iostream>
#include <math.h>

using namespace std;

int main() {
	double x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	double d = fabs(x1 - x2) + fabs(y1 - y2);
	cout.setf(ios::fixed);
	cout.precision(3);
	cout << d;
	return 0;
} 
