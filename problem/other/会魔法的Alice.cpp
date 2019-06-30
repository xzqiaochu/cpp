#include <iostream>

using namespace std;

short list[100005];

int main() {
	int n, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> list[i];
		sum += list[i];
	}
	//cout << sum << endl;
	for (int i = 0; i < n; i++) {
		if (sum - 2 * list[i] == 0) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}
