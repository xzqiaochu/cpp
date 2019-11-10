//D-����
//https://ac.nowcoder.com/acm/contest/1093/D
//athor: xzqiaochu
//status: AC
//algorithm: �߶��� 
//time: 2019/11/10
#include <cstdio>
const int N = 1e5 + 7;
typedef long long int64;

int64 fact[N<<2], M;

int64 qmult(int64 x, int64 y) { //���ٳ˷� 
	int64 ans = 0;
	while (y) {
		if (y & 1)
			ans += x;
		y >>= 1, x <<= 1;
		if (x >= M) //�������� 
			x -= M;
		if (ans >= M)
			ans -= M; 
	}
	return ans;
}

//p q �ڵ����䷶Χ 
//x ���ڵ�
void build(int p, int q, int x) { //�����߶��� 
	if (p == q) { //Ҷ�ӽڵ� 
		fact[x] = p % M;
		return;
	}
	int mid = (p + q) >> 1;
	build(p, mid, x<<1), build(mid+1, q, x<<1|1);
	fact[x] = qmult(fact[x<<1], fact[x<<1|1]);
}

//p q �ڵ����䷶Χ 
//x ���ڵ�
//low high ��ѯ���½� 
int64 query(int p ,int q, int x, int low, int high) { //��ѯ 
	if (p > high || q < low) //�޽��� 
		return 1;
	if (p >= low && q <= high) //�ڵ�����ڲ�ѯ���� 
		return fact[x];
	int mid = (p + q) >> 1; //����ϸ�� 
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

