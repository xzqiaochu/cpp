// ����������program to data)
// ע�����
// 1. ���Ե������dataĿ¼��
// 2. ����ֱ���ñ�׼�����������
// 3. (name).cpp ÿ������ʱ���Զ�����
// 4. �Ƚ�ʱ����˵���ĩ�ո��β�лس�
#include <cstdio>
#include <cstdlib>
#include <ctime>

const int SZ = 107;

char name[SZ], tmp[SZ];

int main() {
    puts("The name of program");
    scanf("%s", name);

	// �������
    sprintf(tmp, "Compiling %s.cpp...", name);
	puts(tmp);
	// ջ�ռ�512M
	// �����������ϸ�ı��룬���о��涼�ᱻ������������
    sprintf(tmp, "g++ %s.cpp -o %s.exe -Wall -Werror -Wl,--stack=536870912", name, name);
	// sprintf(tmp, "g++ %s.cpp -o %s.exe -Wall -Wl,--stack=536870912", name, name);
	if (system(tmp))
		return 0;
	puts("Compiled");

	// ��ʼ����
	for (int i = 0; ; i++) {
		// �жϲ��Դ����Ƿ����
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

		// ���Ʋ��Ե�
        sprintf(tmp, "copy data\\%s%d.in %s.in >nul", name, i, name);
        system(tmp);
        sprintf(tmp, "copy data\\%s%d.out %s.ans >nul", name, i, name);
        system(tmp);

		// ���г���
        sprintf(tmp, "%s.exe < %s.in > %s.out", name, name, name);
		double st = clock();
		system(tmp);
		double ed = clock();

		// �ȶԽ��
        sprintf(tmp, "fc %s.out %s.ans /w >nul", name, name);
		if (system(tmp)) {
			printf("Wrong Answer, Case #%d, Time %.0fms\n", i, ed - st);
			return 0;
		} else {
			printf("Accepted, Case #%d, Time %.0fms\n", i, ed - st);
		}
	}
	// ɾ�����Ե��ļ����ղŸ��Ƶģ�
	sprintf(tmp, "del %s.in >nul", name);
	system(tmp);
	sprintf(tmp, "del %s.out >nul", name);
	system(tmp);
	sprintf(tmp, "del %s.ans >nul", name);
	system(tmp);
}