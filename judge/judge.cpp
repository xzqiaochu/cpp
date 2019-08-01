#include <cstdio>
#include <cstdlib>
#include <ctime>

int main() {
	int n;
	printf("The number of cases: ");
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
			printf("Accepted, Case #%d, Time %.0fms\n", i, ed - st);
		}
	}
} 
