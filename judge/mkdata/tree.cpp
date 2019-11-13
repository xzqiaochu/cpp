// 生成一颗树
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <ctime>
using std::min;

void mainInit() {
	timeb timeseed;
	ftime(&timeseed);
	srand(timeseed.time * 1000 + timeseed.millitm); // 毫秒级随机数种子 
}

int rdm(int a, int b) { // 区间[a, b]内的随机数
	return (rand() % (b - a + 1)) + a;
}

struct Tree {

int size; // 记录剩余节点数量
int maxdegree; // 每个节点的最大度数
bool need_weight; // 是否需要边权
int min_weight; // 边权最小值
int max_weight; // 边权最大值

Tree(int _size, int _maxdegree = 0, bool _need_weight = false, int _min_weight = 1, int _max_weight = 2) {
	size = _size - 1;
	if (_maxdegree == 0)
		maxdegree = size / 2;
	else
		maxdegree = _maxdegree;
	if (_need_weight) {
		need_weight = true;
		min_weight = _min_weight;
		max_weight = _max_weight;
	}
}

// x：子树根节点，sid：孩子开始编号
void mkTreeDfs(int x, int sid) {
	if (size == 0)
		return;
	int sons = rdm(1, min(size, maxdegree)); // 孩子个数
	size -= sons;
	for (int i = 1; i <= sons; i++) {
		int y = sid + i;
		if (need_weight) {
			int weight = rdm(min_weight, max_weight);
			printf("%d %d %d\n", x, y, weight);
		} else {
			printf("%d %d\n", x, y);
		}
		mkTreeDfs(y, sid + sons);
	}
}

void make() {
	mkTreeDfs(1, 1);
}

};



int main() {
	mainInit();
	int n;
	scanf("%d", &n);
	Tree T(n, 0, true, 1, 10);
	T.make();
}