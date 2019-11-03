// 对拍主程序（program to program)
// 注意事项：
// 1. radmon.cpp 和 std.cpp 请手动编译
// 2. my.cpp 每次运行时会自动编译
// 3. 程序直接用标准输入输出即可
// 4. 比较时会过滤掉行末空格和尾行回车
#include <cstdio>
#include <cstdlib>
#include <ctime>

int n;

int main() {
	puts("The number of cases");
	scanf("%d", &n);

	// 编译程序
	puts("Compiling my.cpp...");
	// 我这里是最严格的编译，所有警告都会被视作致命错误
	if (system("g++ my.cpp -o my.exe -Wall -Werror"))
	// if (system("g++ my.cpp -o my.exe -Wall"))
		return 0;
	puts("Compiled");

	// 开始对拍
	for (int i = 1; i <= n; i++) {
		// 产生数据
		system("random.exe > data.in");
		
		// 运行程序
		double st = clock();
		system("my.exe < data.in > data.out");
		double ed = clock();
		system("std.exe < data.in > data.ans");
		
		// 比对
		if (system("fc data.out data.ans /w >nul")) {
			printf("Wrong Answer, Case #%d, Time %.0fms\n", i, ed - st);
			return 0;
		} else {
			printf("Accepted, Case #%d, Time %.0fms\n", i, ed - st);
		}
	}
	// 删除测试点文件
	system("del data.in >nul");
	system("del data.out >nul");
	system("del data.ans >nul");
}