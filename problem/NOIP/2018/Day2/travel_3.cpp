// A-����(travel)
// http://www.mfstem.org/contest/29/problem/A
// author: xzqiaochu
// status: PAC(22/25) TLE
// time: 2019/11/06 
// algorithm: DFSԤ�����һ� 
#include <cstdio>
#include <cstring>
#include <set>
using std::set; 
const int NSZ = 5007, MSZ = NSZ * 2;

int n, m;

int head[NSZ];
struct Edge {
	int to, next;
} edge[MSZ];

//init_dfsʹ��
bool flag, vis[NSZ]; //flagΪdfs�жϱ�� 
int pre[NSZ];
int cyc_sta, use_edge[NSZ], cyc[NSZ]; //�����ڵı�ţ�idΪ�������䣬ż��-1����ֹ˫��߱��ظ�ͳ�ƣ� 

//bool flag, vis[NSZ];
int del1, del2, tmp[NSZ], ans[NSZ];
set<int> s[NSZ];

inline void addEdge(int x, int y) {
	static int tot = 0;
	edge[++tot].to = y;
	edge[tot].next = head[x], head[x] = tot;
}

void init_dfs(int x, int fa) {
	if (vis[x]) {
		pre[x] = 0; //������� 
		cyc_sta = fa; //�����յ� 
		flag = true;
		return; 
	}
	vis[x] = true; //���� 
	for (int i = head[x]; i; i = edge[i].next) {
		if (flag) //�ڴ˴�Ҫ�����ж���ֹ�ź� 
			return; //����´ν���ݹ����жϣ��ᵼ����Ϣ���޸� 
		int y = edge[i].to;
		if (y == fa)
			continue;
		//��¼��Ϣ 
		pre[y] = x;
		use_edge[y] = i; 
		init_dfs(y, x);
	}
} 

void init_cyc() {
	int x = cyc_sta;
	while (x) {
		int from_edge;
		if (use_edge[x] % 2 == 0) //idΪ�������䣬ż��-1
			from_edge = use_edge[x] - 1;
		else
			from_edge = use_edge[x];
		cyc[++cyc[0]] = from_edge;
		x = pre[x];
	}
}

void dfs(int x, int fa) {
	tmp[++tmp[0]] = x;
	s[x].clear();
	for (int i = head[x]; i; i = edge[i].next) {
		int y = edge[i].to;
		if (y == fa || i == del1 || i == del2)
			continue;
		s[x].insert(y);
	}
	if (s[x].empty())
		return;
	set<int>::iterator it; //��������ȫ����������Ȼ�ᱻ�����޸�
	for (it = s[x].begin(); it != s[x].end(); it++)
		dfs(*it, x);
}

bool can() {
	if (ans[1] == 0) //��һ�� 
		return true;
	for (int i = 1; i <= n; i++)
		if (ans[i] != tmp[i])
			return tmp[i] < ans[i];
	return false;
} 

void update() {
	if (can())
		for (int i = 1; i <= n; i++)
			ans[i] = tmp[i];
}

int main() {
//	freopen("travel.in", "r", stdin);
//	freopen("travel.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		addEdge(x, y), addEdge(y, x);
	}
	if (m == n - 1) {
		dfs(1, 0);
		for (int i = 1; i <= n; i++)
			printf("%d ", tmp[i]);
	} else {
		init_dfs(1, 0); //��⻷ 
		init_cyc();
//		puts("");
//		for (int i = 1; i <= cyc[0]; i++)
//			printf("%d ", cyc[i]);
//		return 0; 
		//���ɾ�� 
		for (int i = 1; i <= cyc[0]; i++) {
			del1 = cyc[i], del2 = cyc[i] + 1; //ɾ���߱�� 
			tmp[0] = 0; //��ʼ�� 
			dfs(1, 0);
			update(); 
		}
		for (int i = 1; i <= n; i++)
			printf("%d ", ans[i]);
	}
	return 0;
}
