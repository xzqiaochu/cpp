#include <iostream>

using namespace std;

int gcd(int a, int b) { //�������
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int lcm(int a, int b) { //��С������
	return a / gcd(a, b) * b; //��Ҫд�� a * b / gcd(a, b) ,��ֹ���ݹ�������
}

int main() {
	int a, b;
	cin >> a >> b;
	cout << gcd(a, b) << ' ' << lcm(a, b);
}
