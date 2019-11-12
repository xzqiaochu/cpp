// 评测主程序（program to data)
// 注意事项：
// 1. 测试点请放在data目录下
// 2. 程序直接用标准输入输出即可
// 3. (name).cpp 每次运行时会自动编译
// 4. 比较时会过滤掉行末空格和尾行回车
#include <cstdio>
#include <cstdlib>
#include <ctime>

const int SZ = 107;

char name[SZ], tmp[SZ];

int main() {
    puts("The name of program");
    scanf("%s", name);

	// 编译程序
    sprintf(tmp, "Compiling %s.cpp...", name);
	puts(tmp);
	// 栈空间512M
	// 我这里是最严格的编译，所有警告都会被视作致命错误
    sprintf(tmp, "g++ %s.cpp -o %s.exe -Wall -Werror -Wl,--stack=536870912", name, name);
	// sprintf(tmp, "g++ %s.cpp -o %s.exe -Wall -Wl,--stack=536870912", name, name);
	if (system(tmp))
		return 0;
	puts("Compiled");

	// 开始评测
	for (int i = 0; ; i++) {
		// 判断测试带点是否存在
		sprintf(tmp, "data\\%s%d.in", name, i);
		if (FILE *file = fopen(tmp, "r"))
			fclose(file);
		else
			break;
		sprintf(tmp, "data\\%s%d.out", name, i);
		if (FILE *file = fopen(tmp, "r"))
			fclose(file);
		else
			break;

		// 复制测试点
        sprintf(tmp, "copy data\\%s%d.in %s.in >nul", name, i, name);
        system(tmp);
        sprintf(tmp, "copy data\\%s%d.out %s.ans >nul", name, i, name);
        system(tmp);

		// 运行程序
        sprintf(tmp, "%s.exe < %s.in > %s.out", name, name, name);
		double st = clock();
		system(tmp);
		double ed = clock();

		// 比对结果
        sprintf(tmp, "fc %s.out %s.ans /w >nul", name, name);
		if (system(tmp)) {
			printf("Wrong Answer, Case #%d, Time %.0fms\n", i, ed - st);
			return 0;
		} else {
			printf("Accepted, Case #%d, Time %.0fms\n", i, ed - st);
		}
	}
	// 删除测试点文件（刚才复制的）
	sprintf(tmp, "del %s.in >nul", name);
	system(tmp);
	sprintf(tmp, "del %s.out >nul", name);
	system(tmp);
	sprintf(tmp, "del %s.ans >nul", name);
	system(tmp);
}