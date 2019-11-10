//C-奶牛的草场
//http://socode.online/problems/368?contest=37
//author: xzqiaochu
//status: AC
//time: 2019/11/08
#include <cstdio>
#include <algorithm>
const int SZ = 1e6 + 7;

int n, f[SZ], ed[SZ]; 
struct Node {
	int st, ed;
	bool operator< (const Node b) const {
		return ed < b.ed || (ed == b.ed && st < b.st); //不写第二关键字也行 
	}
} a[SZ];

void dp() {
	for (int i = 1; i <= n; i++) {
		int len = a[i].ed - a[i].st + 1;
		//在[0, i - 1]区间内查找
		//0：防止找不到
		//i-1：当前i下标还未赋值 
		int k = std::lower_bound(ed, ed + i, a[i].st) - 1 - ed; //找小于x的最大元素 
		f[i] = std::max(f[k] + len, f[i - 1]); //选/不选 
		ed[i] = a[i].ed; //做一个影子，方便查找 
	}
}
//如果两个区间的左端点相同，并不影响dp
//因为，dp[i]保存的是（考虑到i时的）最优解 


int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &a[i].st, &a[i].ed);
	std::sort(a + 1, a + n + 1);
	dp();
	printf("%d", f[n]);
	return 0;
}
