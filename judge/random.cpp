// 测试点生成
#include <cstdio>
#include <cstdlib>
#include <ctime>

int rdm(int a, int b) { // 区间[a, b]内的随机数
	return (rand() % (b - a + 1)) + a;
}

int main() {
	struct timeb timeseed;
	ftime(&timeseed);
	srand(timeseed.time * 1000 + timeseed.millitm); // 毫秒级随机数种子 
	// data
	int a = rdm(1, 9), b = rdm(1, 9);
	// output
	printf("%d %d\n", a, b);
	return 0;
}
