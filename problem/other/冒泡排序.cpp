#include <iostream>

using namespace std;

int main() {
	int n;
	int *list;
	cout << "�����������";
	cin >> n;
	list = new int[n + 1];
	cout << endl << "������" << n << "������";
	for (int i = 1; i <= n; i++) {
		cin >> list[i];
	}
	
	//ð������ 
	int m = n;
	while (m > 1) {
		for (int i = 1; i <= m; i++) {
			if (list[i] > list[i + 1]) {
				int temp = list[i];
				list[i] = list[i + 1];
				list[i + 1] = temp;
			}
		}
		m--;
	}
	
	for (int j = 1; j <= n; j++) {
		cout << list[j] << " ";
	}
	return  0;
}
