/* 随机数生成器
描述：本程序采用毫米级随机数种子，保证两次运行所产生的随机数序列不同
用途：测试点生成
注意事项：比赛/做题 时请不要这样写，原因如下：
1. ftime函数不一定能通过编译
2. 有些考察随机数的题目，直接用rand()就行，题目的数据是设计好的（用srand()反而通过不了) */
#include <cstdio>
#include <cstdlib>
#include <ctime>

void mainInit() {
	timeb timeseed; // 这是一个结构体
	ftime(&timeseed); // 获取目前时间
	// 设置随机数种子为系统时间，不然的话，每次运行程序获取的随机数序列都是相同的
	srand(timeseed.time * 1000 + timeseed.millitm); // 毫秒级随机数种子 
}

int rdm(int a, int b) {
	return (rand() % (b - a + 1)) + a;
}

int main() {
	mainInit();
	int cnt1 = 0, cnt2 = 0;
	for (int i = 1; i <= 100000; i++) {
		int temp = rdm(0, 1);
		if (temp == 0) cnt1++;
		else cnt2++;
	}
	printf("%d %d", cnt1, cnt2);
	return 0;
}