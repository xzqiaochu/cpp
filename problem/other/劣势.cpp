#include <iostream>
#include <fstream>

//#define cin fin
//#define cout fout

using namespace std;

ifstream fin("weakness.in");
ofstream fout("weakness.out");

int main() {
	int n, last = 0, now, ans = 0;
	bool last_s = false, now_s = false, flag = false;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> now;
		now_s = last > now;
		if (last_s && now_s) {
			if (flag) {
				ans++;
			}else{
				ans += 3;
				flag = true; 
			}
		}else{
			flag = false;
		}
		last_s = now_s;
		last = now;
	}
	cout << ans;
	return 0;
}
