//����1g 5g 25g 30g 50g �������ɣ�ÿ����������ѡ1����50g�������ѡ6��
//Ҫ������mg��������������ʹ�õ�������n
//��������m m>=111
//�������n 

#include <iostream>

using namespace std;

int main() {
	int m = 0, n = 0;
	cin >> m;
	
	m -= 1 + 5 + 25 + 30 + 50;
	n += 5; 
	
	int temp = m / 50;
	if (temp > 5) temp = 5;
	n += temp;
	m -= temp * 50;
	cout << "50*" << temp + 1;
	
	temp = m / 30;
	n += temp;
	m -= temp * 30;
	cout << "+30*" << temp + 1;
	
	temp = m / 25;
	n += temp;
	m -= temp * 25;
	cout << "+25*" << temp + 1;
	
	temp = m / 5;
	n += temp;
	m -= temp * 5;
	cout << "+5*" << temp + 1;
	
	n += m;
	cout << "+1*" << temp + 1 << endl;
	
	cout << n;
	return 0; 
}
