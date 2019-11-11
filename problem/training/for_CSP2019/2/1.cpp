//1-友好数对
//author: xzqiaochu
//status: 已过样例 
//time: 2019/11/11
#include <cstdio>
#include <cmath>
const int SZ = 2e6 + 7;

int L, R, len, ans;

int calc(int x) {
	int a, b, y, tmp, cnt = 0;
	
	for (int i = 1; i <= len; i++) {
		tmp = pow(10, i);
		a = x / tmp;
		b = x % tmp;
		y = b * pow(10, len + 1 - i) + a;
		if (x == y) //一定要break，不然有的数会被多算，比如1212-2121 
			break;
		if (y <= R && y >= L)
			cnt++;
	}
	return cnt;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		ans = 0;
		scanf("%d%d", &L, &R);
		len = log10(L);
		for (int i = L; i <= R; i++)
			ans += calc(i);
		printf("%d\n", ans / 2);
	}
	return 0;
}
