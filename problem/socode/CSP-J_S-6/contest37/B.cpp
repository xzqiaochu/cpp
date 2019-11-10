//B-��ǿ����̨��
//http://socode.online/problems/367?contest=37
//author: xzqiaochu
//status: AC
//time: 2019/11/08
#include <cstdio>
#include <algorithm>
const int KSZ = 17;
const int INF = 0x3f3f3f3f;

int n, m, k;
int a[KSZ], f, ans = INF;

inline bool use(int x) {
	return f & (1 << (x - 1));
}

int find(int r, int l) {
	for (int i = 1; i <= k; i++) {
		if (a[i] > l)
			return -1;
		if (a[i] >= r && a[i] <= l && use(i))
			return a[i];
	}
	return -1;
}

void calc() {
	int p = 0, cnt = 0, go = m; //p=0����ʼ�ڵ�0��̨���� 
	int stage;
	while (p < n) {
		cnt++;
		stage = find(p + 1, p + go);
		if (stage == -1)
			p += go;
		else
			p = stage, go++;
	}
	ans = std::min(ans, cnt);
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= k; i++)
		scanf("%d", a + i);
	int end = 1 << k; //�ϸ���˵����k=0ʱ��endӦ�õ���0�����ⲻ����Ҳ�У� 
	for (f = 0; f <= end; f++)
		calc();
	printf("%d", ans);
	return 0;
}
