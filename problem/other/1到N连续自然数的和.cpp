#include <iostream>

using namespace std;

int work(int n); 

int main() {
	int n;
	cin >> n;
	cout << work(n); 
	return 0;
}

int work(int n) {
	if (n == 1) {
		return 1;
	}
	return n + work(n-1);
}
