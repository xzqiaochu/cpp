// B-��С�� 
// https://ac.nowcoder.com/acm/contest/1093/B
// author: xzqiaochu
// status: PAC(50%)
// time: 2019/11/03
#include <cstdio>
#include <set>
using namespace std;

int n, k, ans;
multiset<int> s;

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		int tmp;
		scanf("%d", &tmp);
		s.insert(tmp);
	}
	for (int i = 1; i <= k; i++) {
		if (s.empty()) {
			ans = 0;
			break;
		} 
		//���ɾ����һ��
		int try1 = *(--s.end()) - *(++s.begin());
		//���ɾ�����һ��
		int try2 = *(--(--s.end())) - *s.begin();
		if (try1 < try2) //ɾ����һ������ 
			s.erase(s.begin()), ans = try1;
		else
			s.erase(--s.end()), ans = try2;
	}
	printf("%d", ans);
	return 0;
}
