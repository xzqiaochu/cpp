#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
    	if (i % 2 == 0) {
    		cout << i * n + 1;
    		for (int j = i * n + 2; j <= i * n + n; j++) cout << ' ' << j;
		} else {
			cout << i * n + n;
			for (int j = i * n + n - 1; j >= i * n + 1; j--) cout << ' ' << j;
		}
		cout << endl;
	}
    return 0;
}
