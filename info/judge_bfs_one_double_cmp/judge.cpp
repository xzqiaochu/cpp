#include <cstdio>
#include <cstdlib>
#include <ctime>

int main() {
	int n;
	printf("请输入测试点数目：");
	scanf("%d", &n); 
	for (int i = 1; i <= n; i++) {
		system("random.exe > data.in");
		double t1 = clock();
		system("one.exe < data.in > one.out");
		double t2 = clock();
		system("double.exe < data.in > double.out");
		double t3 = clock();
		if (system("fc one.out double.out")) {
			puts("Different");
			return 0;
		} else {
			printf("Same, 测试点 #%d, one用时 %dms, double用时 %dms\n", i, (int)(t2 - t1), (int)(t3 - t2));
		}
	}
}
