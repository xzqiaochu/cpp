#include <iostream>

using namespace std;

int gcd(int a, int b) { //最大公因数
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int lcm(int a, int b) { //最小公倍数
	return a / gcd(a, b) * b; //不要写成 a * b / gcd(a, b) ,防止数据过大而溢出
}

int main() {
	int a, b;
	cin >> a >> b;
	cout << gcd(a, b) << ' ' << lcm(a, b);
}
