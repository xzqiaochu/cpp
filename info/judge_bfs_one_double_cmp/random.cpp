//������Ե�����
//ע�⣺��ĩ���endl 
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int rdm(int a, int b) { //����[a, b]�ڵ������
	return (rand() % (b - a + 1)) + a;
}

int main() {
	struct timeb timeseed;
	ftime(&timeseed);
	srand(timeseed.time * 1000 + timeseed.millitm); //���뼶��������� 
	//����Ϊ��������
	cout << rdm(100, 1000) << ' ' << rdm(1, 1000) << endl; 
	return 0;
}
