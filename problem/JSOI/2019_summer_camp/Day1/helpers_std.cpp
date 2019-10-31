/* helpers PAC(3WA)
author: std */
#include <bits/stdc++.h>

#define LL long long

const int MAXB = 1e8 + 10;
char ibuf[MAXB], *icp = ibuf;

void rd(int &x)
{
	x = 0;
	while (*icp < '0' || '9' < *icp)
		icp++;
	while ('0' <= *icp && *icp <= '9')
		x = x * 10 + *icp++ - 48;
}

char obuf[MAXB], *ocp = obuf;

void write(int x)
{
	static char s[10];
	static int top = 0;
	for (; x; x /= 10)
		s[top++] = x % 10 + 48;
	while (top)
		*ocp++ = s[--top];
	*ocp++ = ' ';
}

const int mod = 998244353;
const int MAXN = 10000010;

inline int mul(const int a, const int b) { return (LL)a * b % mod; }

inline int qpow(int a, int x)
{
	int res = 1;
	for (; x; x >>= 1, a = mul(a, a))
		if (x & 1)
			res = mul(res, a);
	return res;
}

int n, sum, inv;
int a[MAXN];

int main()
{
	// freopen("helpers.in", "r", stdin);
	// freopen("helpers.out", "w", stdout);
	ibuf[fread(ibuf, 1, MAXB, stdin)] = '\0';
	rd(n);
	sum = 0;
	for (int i = 0; i < n; i++)
	{
		rd(a[i]);
		sum += a[i];
	}
	inv = qpow(sum, mod - 2);
	for (int i = 0; i < n; i++)
		write(mul(a[i], inv));
	fwrite(obuf, 1, ocp - obuf, stdout);
	return 0;
}