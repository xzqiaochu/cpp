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
	// �����������ϸ�ı��룬���о��涼�ᱻ������������
	if (system("g++ my.cpp -o my.exe -Wall -Werror"))
	// if (system("g++ my.cpp -o my.exe -Wall"))
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