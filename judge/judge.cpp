// ����������
// my.cpp ÿ������ʱ���Զ�����
// radmon.cpp �� std.cpp ���ֶ�����
// ע�����
// 1. ����ֱ���ñ�׼����������ɣ����ĳ����Ѿ�����������ض����ˣ�
// 2. �Ƚ�ʱ����˵���ĩ�ո��β�лس�
#include <cstdio>
#include <cstdlib>
#include <ctime>

int main() {
	puts("Compiling my.cpp ...");
	// �����������ϸ�ı��룬���о��涼�ᱻ������������
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
