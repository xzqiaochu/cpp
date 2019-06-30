#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int work(int n); 

int main() {
	while(1) {
		int n;
	    cout << "求1到N连续自然数的和" << endl;
	    cout << "请输入N（输入0退出程序）："; 
	    cin >> n;
	    if (n == 0) break;
	    cout << "1到" << n << "连续自然数的和为：" << work(n) << endl;
	}
	return 0;
}

int work(int n) {
	if (n == 1) {
		return 1;
	}
	return n + work(n-1);
}
