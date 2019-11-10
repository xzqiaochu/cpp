//D-函数
//https://ac.nowcoder.com/acm/contest/1093/D
//athor: xzqiaochu
//status: AC
//algorithm: 线段树 
//time: 2019/11/10
#include <cstdio>
const int N = 1e5 + 7;
typedef long long int64;

int64 fact[N<<2], M;

int64 qmult(int64 x, int64 y) { //慢速乘法 
	int64 ans = 0;
	while (y) {
		if (y & 1)
			ans += x;
		y >>= 1, x <<= 1;
		if (x >= M) //减法更快 
			x -= M;
		if (ans >= M)
			ans -= M; 
	}
	return ans;
}

//p q 节点区间范围 
//x 根节点
void build(int p, int q, int x) { //构建线段树 
	if (p == q) { //叶子节点 
		fact[x] = p % M;
		return;
	}
	int mid = (p + q) >> 1;
	build(p, mid, x<<1), build(mid+1, q, x<<1|1);
	fact[x] = qmult(fact[x<<1], fact[x<<1|1]);
}

//p q 节点区间范围 
//x 根节点
//low high 查询上下界 
int64 query(int p ,int q, int x, int low, int high) { //查询 
	if (p > high || q < low) //无交集 
		return 1;
	if (p >= low && q <= high) //节点包含于查询区间 
		return fact[x];
	int mid = (p + q) >> 1; //继续细分 
	int64 a = query(p, mid, x<<1, low, high);
	int64 b = query(mid + 1, q, x<<1|1, low, high);
	return qmult(a, b); 
}

int main() {
	int q, n, r;
	scanf("%d%lld", &q, &M);
	build(1, 1e5, 1);
	while (q--) {
		scanf("%d%d", &n, &r);
		printf("%lld\n", query(1, 1e5, 1, r + 1, n));
	}
	return 0;
}

