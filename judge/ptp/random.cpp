// ���Ե����ɳ������ֶ����룩
#include <cstdio>
#include <cstdlib>
#include <ctime>

void mainInit() {
	timeb timeseed;
	ftime(&timeseed);
	srand(timeseed.time * 1000 + timeseed.millitm); // ���뼶��������� 
}

int rdm(int a, int b) { // ����[a, b]�ڵ������
	return (rand() % (b - a + 1)) + a;
}

int main() {
	mainInit(); 
	// data
	int a = rdm(1, 9), b = rdm(1, 9);
	// output
	printf("%d %d\n", a, b);
	return 0;
}
