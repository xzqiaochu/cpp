#include <cstdio>
#include <cstdlib>
#include <ctime>

int main() {
	int n;
	printf("请输入测试点数目：");
	scanf("%d", &n); 
	for (int i = 1; i <= n; i++) {
		system("random.exe > data.in");
		double st = clock();
		system("my.exe < data.in > data.out");
		double ed = clock();
		system("std.exe < data.in > data.ans");
		if (system("fc data.out data.ans")) {
			puts("Wrong Answer");
			return 0;
		} else {
			printf("Accepted, 测试点 #%d, 用时 %.01fms\n", i, ed - st);
		}
	}
} 
