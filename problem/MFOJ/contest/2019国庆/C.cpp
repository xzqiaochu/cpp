// C-魔幻教主(magic)
// http://www.mfstem.org/contest/62/problem/C
// author: xzqiaochu(following kelvin)
// status: AC
// time: 2019/11/1
#include <cstdio>
#include <algorithm>
#include <cmath>

const int N = 1e6 + 7;

int n, q, a[N], aa[N], pos[N], add[N], blk;

void resort(int x) { // 对第x块进行排序 
	int low = (x-1)*blk+1, high = std::min(x*blk, n); // 计算首元素和末尾元素
	// 第i块的末尾元素为i*blk
	// 第i-1块的末尾元素为(i-1)*blk
	// 所以第i块的首元素为(i-1)*blk+1
	std::sort(aa+low, aa+high+1); // 注意第二个参数为末尾元素的后继 
}

void update(int x, int y, int v) { // 更新操作 
	if (pos[x] == pos[y]) {
		// 1. 处理x与y在同一个块的情况
		for (int i = x; i <= y; i++)
			a[i] = aa[i] = a[i] + v; // 更新a[i]和aa[i]（影子数组） 
		resort(pos[x]); // 重新对此块进行排序 
	}
	else {
		// 2.1 处理x与y不在同一个块时，两头零碎部分的情况
		for (int i = x; i <= pos[x]*blk; i++) // 头部零碎 
			a[i] = aa[i] = a[i] + v;
		resort(pos[x]); 
		for (int i = (pos[y]-1)*blk+1; i <= y; i++) // 尾部零碎 
			a[i] = aa[i] = a[i] + v;
		resort(pos[y]);
		// 2.2 处理整个块的情况
		for (int i = pos[x]+1; i < pos[y]; i++) // 遍历中间完整包含的块 
			add[i] += v;
	}
}

int search(int x, int v) { // 二分查找 
	int low = (x-1)*blk+1, high = std::min(x*blk, n), stub = high; // stub时对high的备份 
	while (low <= high) { // 二分模板 
		int mid = low+high >> 1;
		if (aa[mid] < v) // 合法 
			low = mid + 1; // 小加 
		else
			high = mid - 1; // 大减 
	}
	// low为合法的最大值 
	return stub - low + 1; // 区间长度要加1 
}

int query(int x, int y, int v) { // 查询 
	int sum = 0;
	if (pos[x] == pos[y]) {
		// 1. 处理x与y在同一个块
		for (int i = x; i <= y; i++)
			if (a[i]+add[pos[i]] >= v) // 注意要加add[pos[i]] 
				++sum;
	} else {
		// 2.1 处理x与y不在同一个块时，两头零碎部分的情况
		for (int i = x; i <= pos[x]*blk; i++) // 头部零碎 
			if (a[i]+add[pos[i]] >= v)
				++sum;
		for (int i = (pos[y]-1)*blk+1; i <= y; i++) // 尾部零碎 
			if (a[i]+add[pos[i]] >= v)
				++sum;
		// 2.2 处理整个块的情况
		for (int i = pos[x]+1; i < pos[y]; i++) // 遍历中间块 
			sum += search(i, v-add[i]); // 二分查找 
	}
	return sum;
}

int main() {
//	freopen("magic.in", "r", stdin);
//	freopen("magic.out", "w", stdout);
	scanf("%d%d", &n, &q);
	blk = sqrt(n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		pos[i] = (i - 1) / blk + 1; // 计算所属块号 
		aa[i] = a[i]; // 做一个影子，方便排序统计用 
	}
	int m = (n + blk - 1) / blk; // 上取整 
	for (int i = 1; i <= m; i++) // 对每块分别进行排序 
		resort(i);
	for (int i = 1; i <= q; i++) {
		char cmd[2];
		int x, y, v;
		// 这里不能用%c，不然会把上一行的回车读入 
		scanf("%s%d%d%d", cmd, &x, &y, &v);
		if (cmd[0] == 'M')
			update(x, y, v);
		else
			printf("%d\n", query(x, y, v));
	}
}