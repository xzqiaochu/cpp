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
	
	//ѡ������ 
	int start = 1;
	while (start < n - 1) {
		int min = list[start + 1];
		int min_id = start + 1;
		for (int i = start + 2; i <= n; i++) {
			if (list[i] < min) {
				min = list[i];
				min_id = i;
			}
		}
		int temp = list[start];
		list[start] = list[min_id];
		list[min_id] = temp;
		start++;
	}
	
	for (int j = 1; j <= n; j++) {
		cout << list[j] << " ";
	}
	return  0;
}
