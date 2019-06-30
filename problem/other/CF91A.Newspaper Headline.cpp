#include <iostream>
#include <cstring>

using namespace std;

bool search(string substr, string str) {
	int j = 0;
	for (int i = 0; i < substr.length(); i++) {
		char c = substr[i];
		bool found = false;
		for (; j < str.length(); j++) {
			if (str[j] == c) {
				found = true;
				break;
			}
		}
		if (!found) return false;
		j++;
	}
	return true;
}

int main() {
	string s1, s2;
	string sa = "";
	cin >> s1 >> s2;
	bool ok = false;
	for (int i = 1; i <= 10000; i++) {
		sa += s1;
		if (search(s2, sa)) {
			cout << i;
			ok = true;
			break;
		}
	}
	if (!ok) cout << -1;
	return 0;
}
