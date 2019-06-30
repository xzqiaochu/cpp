//毫秒级随机数测试 
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int rdm(int a, int b) {
	return (rand() % (b - a + 1)) + a;
}

int main() {
	struct timeb timeseed;
	ftime(&timeseed);
	srand(timeseed.time * 1000 + timeseed.millitm);
	int cnt1 = 0, cnt2 = 0;
	for (int i = 1; i <= 100000; i++) {
		int temp = rdm(0, 1);
		if (temp == 0) cnt1++;
		else cnt2++;
	}
	cout << cnt1 << endl << cnt2 << endl;
	return 0;
}