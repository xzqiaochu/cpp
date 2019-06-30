#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int n, start = 0;
	string str, r = "";
	cin >> str >> n;
	for (int i = 0; i < str.length() - n; i++) {
		int minn = str[start];
		int flag = start;
		for (int j = start; j <= n + i; j++) {
			if (str[j] < minn) {
				minn = str[j];
				flag = j;
			}
		}
		start = flag + 1;
		r += minn;
	}
	while(r != "0" && r[0] == '0') r.erase(0, 1);
	cout << r;
	return 0;
}
