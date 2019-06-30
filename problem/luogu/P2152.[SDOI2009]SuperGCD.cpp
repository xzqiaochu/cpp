#include <iostream>
#include <string>

using namespace std;

inline void clear(string & a) {
	while (a.length() > 0 && a[0] == '0') a.erase(0, 1);
	if (a == "") a = "0";
}

bool isBigger(string a, string b) {
	clear(a);
	clear(b);
	if (a.length() > b.length()) return true;
	if (a.length() == b.length() && a >= b) return true;
	return false;
}

string sub(string a, string b) {
	while (a.length() < b.length()) a = '0' + a;
	while (a.length() > b.length()) b = '0' + b;
	bool aBigger = true;
	if (!isBigger(a, b)) {
		aBigger = false;
		swap(a, b);
	}
	for (int i = a.length(); i >= 0; i--) {
		if (a[i] >= b[i]) {
			a[i] -= b[i] - '0';
		}else{
			a[i - 1] -= 1;
			a[i] -= b[i] - '0' - 10;
		}
	}
	clear(a);
	if (!aBigger) a = '-' + a;
	return  a; 
}

string mod(string a, string b) {
	clear(a);
	clear(b);
	if (b == "0") return "Error!";
	string rmd = "", qt = "";
	for (int i = 0; i < a.length(); i++) {
		rmd += a[i];
		qt += '0';
		while (isBigger(rmd, b)) {
			qt[qt.length() - 1]++;
			rmd = sub(rmd, b);
		}
	}
	clear(rmd);
	return rmd;
}

string gcd(string a, string b){
    clear(a);
    clear(b);
    if(b == "0"){
        return a;
    }else{
        return gcd(b, mod(a, b)); 
    }
}

int main() {
	string a, b;
	cin >> a >> b;
	cout << gcd(a, b);
	return 0;
}
