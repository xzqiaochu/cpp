#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int work(int n); 

int main() {
	while(1) {
		int n;
	    cout << "��1��N������Ȼ���ĺ�" << endl;
	    cout << "������N������0�˳����򣩣�"; 
	    cin >> n;
	    if (n == 0) break;
	    cout << "1��" << n << "������Ȼ���ĺ�Ϊ��" << work(n) << endl;
	}
	return 0;
}

int work(int n) {
	if (n == 1) {
		return 1;
	}
	return n + work(n-1);
}
