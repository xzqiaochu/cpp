// 简单数学题 (mt.in/out)
// author: xzqiaochu
// status: AC 
// time: 2019/11/04
#include <cstdio>
#include <cmath>

int b, c;

int sqr(int x) {
	for (int i = sqrt(x); ; i++) {
		if (i * i == x)
			return i;
		if (i * i > x)
			return -1;
	}
}

int main() {
	scanf("x^2%dx%d", &b, &c);
	int d = b*b - 4*c; //根的判别式 
	if (d < 0) //方程无解 
		printf("-1");
	else if (d == 0) { //方程有两个相同的根 
		if (b % 2 == 0)
			printf("(x%+d)^2", b / 2);
		else
			printf("-1"); //根不为整数 
	} else {
		int sd = sqr(d); //开根号 
		if (sd == -1) //开跟号后不为整数 
			printf("-1");
		else {
			if ((- b - sd) % 2 == 0 && (- b + sd) % 2 == 0) {
				int x1 = (- b - sd) / 2, x2 = (- b + sd) / 2;
				printf("(x%+d)(x%+d)", -x1, -x2);
			} else
				printf("-1"); //根不为整数 
		}
	}
	return 0;
} 
