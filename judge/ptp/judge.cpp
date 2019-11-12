// ����������program to program)
// ע�����
// 1. radmon.cpp �� std.cpp ���ֶ�����
// 2. my.cpp ÿ������ʱ���Զ�����
// 3. ����ֱ���ñ�׼�����������
// 4. �Ƚ�ʱ����˵���ĩ�ո��β�лس�
#include <cstdio>
#include <cstdlib>
#include <ctime>

int n;

int main() {
	puts("The number of cases");
	scanf("%d", &n);

	// �������
	puts("Compiling my.cpp...");
	// ջ�ռ�512M
	// �����������ϸ�ı��룬���о��涼�ᱻ������������
	if (system("g++ my.cpp -o my.exe -Wall -Werror -Wl,--stack=536870912"))
	// if (system("g++ my.cpp -o my.exe -Wall -Wl,--stack=536870912"))
		return 0;
	puts("Compiled");

	// ��ʼ����
	for (int i = 1; i <= n; i++) {
		// ��������
		system("random.exe > data.in");
		
		// ���г���
		double st = clock();
		system("my.exe < data.in > data.out");
		double ed = clock();
		system("std.exe < data.in > data.ans");
		
		// �ȶ�
		if (system("fc data.out data.ans /w >nul")) {
			printf("Wrong Answer, Case #%d, Time %.0fms\n", i, ed - st);
			return 0;
		} else {
			printf("Accepted, Case #%d, Time %.0fms\n", i, ed - st);
		}
	}
	// ɾ�����Ե��ļ�
	system("del data.in >nul");
	system("del data.out >nul");
	system("del data.ans >nul");
}