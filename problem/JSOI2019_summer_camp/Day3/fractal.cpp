// 分形(fractal)
// author: xzqiaochu
// status: AC
#include <cstdio>

int yc, xc;
double sy, sx, p, q;

struct comp
{
	double x, y;
	comp(double x = 0, double y = 0) : x(x), y(y) {}
};

comp operator + (comp a, comp b) {
	return comp(a.x + b.x, a.y + b.y);
}
comp operator - (comp a, comp b) {
	return comp(a.x - b.x, a.y - b.y);
}
comp operator * (comp a, comp b) {
	return comp(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}

double len2(comp a)
{
	return a.x * a.x + a.y * a.y;
}

comp c;
comp z[101];

bool check(comp a)
{
	z[0] = a;
	if (len2(z[0]) >= 100)
		return false;
	for (int i = 1; i <= 100; i++)
	{
		z[i] = z[i - 1] * z[i - 1] + c;
		if (len2(z[i]) >= 100)
			return false;
	}
	return true;
}

int main()
{
	// freopen("fractal.in", "r", stdin);
	// freopen("fractal.out", "w", stdout);
	scanf("%d%d", &yc, &xc);
	scanf("%lf%lf", &sy, &sx);
	scanf("%lf%lf", &p, &q);
	c = comp(p, q);
	for (int i = 0; i < yc; i++)
	{
		for (int j = 0; j < xc; j++)
			if (check(comp(sy + j * 0.005, sx + i * 0.01)))
				putchar('a');
			else
				putchar(' ');
		puts("");
	}
	return 0;
}
