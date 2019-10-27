// 对拍主程序
// my.cpp 每次运行时会自动编译
// radmon.cpp 和 std.cpp 请手动编译
// 注意事项：
// 1. 程序直接用标准输入输出即可（对拍程序已经将输入输出重定向了）
// 2. 比较时会过滤掉行末空格和尾行回车
#include <cstdio>
#include <cstdlib>
#include <ctime>

int main() {
	puts("Compiling my.cpp ...");
	// 我这里是最严格的编译，所有警告都会被视作致命错误
	if (system("g++ my.cpp -o my.exe -Wall -Wextra -Werror"))
	{
		puts("Compile Error my.cpp");
		return 0;
	}
	puts("Compiled");
	int n;
	printf("The number of cases: ");
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		system("random.exe > data.in");
		double st = clock();
		system("my.exe < data.in > data.out");
		double ed = clock();
		system("std.exe < data.in > data.ans");
		if (system("fc data.out data.ans /w")) {
			puts("Wrong Answer");
			return 0;
		} else {
			printf("Accepted, Case #%d, Time %.0fms\n", i, ed - st);
		}
	}
} 
