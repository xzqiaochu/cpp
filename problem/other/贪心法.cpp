//现有1g 5g 25g 30g 50g 砝码若干，每个砝码至少选1个，50g砝码最多选6个
//要求搭配出mg的质量，求最少使用的砝码数n
//输入整数m m>=111
//输出整数n 

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
