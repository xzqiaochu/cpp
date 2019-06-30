#include <iostream>
#include <cmath>
#include <algorithm>

#define pi 3.1415926535

using namespace std;

struct p_struct {
	int sign, x, y;
	double r;
	bool operator < (const p_struct & p) const {
		return sign < p.sign;
	}
} p[6];

int main() {
	int n, x1, y1, x2, y2, s = 0;
	cin >> n >> x1 >> y1 >> x2 >> y2;
	for (int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y;
		p[i].sign = i;
	}
	do {
		for (int i = 0; i < n; i++) {
			p[i].r = 0x3f3f3f3f;
			p[i].r = min(p[i].r, abs((double)(x1 - p[i].x)));
			p[i].r = min(p[i].r, abs((double)(x2 - p[i].x)));
			p[i].r = min(p[i].r, abs((double)(y1 - p[i].y)));
			p[i].r = min(p[i].r, abs((double)(y2 - p[i].y)));
			for (int j = 0; j < i; j++) {
				double d = sqrt(pow(abs(p[j].x - p[i].x), 2) + pow(abs(p[j].y - p[i].y), 2)) - p[j].r;
				if (d < 0) d = 0;
				p[i].r = min(p[i].r, d);
			}
		}
		int s_this = 0;
		for (int i = 0; i < n; i++) s_this += pow(p[i].r, 2) * pi;
		s = max(s, s_this);
	} while (next_permutation(p, p + n));
	int s_total = abs(x1 - x2) * abs(y1 - y2);
	cout << (int)(s_total - s + 0.5);
	return 0;
}
