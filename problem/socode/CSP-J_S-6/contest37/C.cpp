//C-��ţ�Ĳݳ�
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
		return ed < b.ed || (ed == b.ed && st < b.st); //��д�ڶ��ؼ���Ҳ�� 
	}
} a[SZ];

void dp() {
	for (int i = 1; i <= n; i++) {
		int len = a[i].ed - a[i].st + 1;
		//��[0, i - 1]�����ڲ���
		//0����ֹ�Ҳ���
		//i-1����ǰi�±껹δ��ֵ 
		int k = std::lower_bound(ed, ed + i, a[i].st) - 1 - ed; //��С��x�����Ԫ�� 
		f[i] = std::max(f[k] + len, f[i - 1]); //ѡ/��ѡ 
		ed[i] = a[i].ed; //��һ��Ӱ�ӣ�������� 
	}
}
//��������������˵���ͬ������Ӱ��dp
//��Ϊ��dp[i]������ǣ����ǵ�iʱ�ģ����Ž� 


int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &a[i].st, &a[i].ed);
	std::sort(a + 1, a + n + 1);
	dp();
	printf("%d", f[n]);
	return 0;
}
