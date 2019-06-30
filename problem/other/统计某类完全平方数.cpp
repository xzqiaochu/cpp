#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n, cnt = 0;
	cin >> n;
	for (int i = 11; i <= sqrt(n); i++) {
		int abc = i * i; 
		int a = abc % 10;
		int b = (int)(abc / 10) % 10;
		int c = abc / 100;
		if (a == b || b == c || a == c)  {
			cnt++;
			//cout << abc << ' ' << i << endl;
		}
	}
	cout << cnt;
	return 0;
}
