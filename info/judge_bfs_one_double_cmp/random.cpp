//随机测试点生成
//注意：文末输出endl 
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int rdm(int a, int b) { //区间[a, b]内的随机数
	return (rand() % (b - a + 1)) + a;
}

int main() {
	struct timeb timeseed;
	ftime(&timeseed);
	srand(timeseed.time * 1000 + timeseed.millitm); //毫秒级随机数种子 
	//以下为生成数据
	cout << rdm(100, 1000) << ' ' << rdm(1, 1000) << endl; 
	return 0;
}
