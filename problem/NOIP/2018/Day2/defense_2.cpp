// [NOIP2018]Day2-C-��������(defense)
// http://www.mfstem.org/contest/29/problem/C
// author: xzqiaochu
// status: PAC(11/25)
// algorithm: ddp 
// time: 2019/11/11
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using std::min;
typedef long long int64;
const int VSZ = 3e5 + 7, ESZ = VSZ * 2;
const int MAXT = 30;
const int64 INF = 1e18, EPS = 1000;

int n, q;

int v[VSZ]; //��Ȩ 
int head[VSZ]; //��ʽǰ���� 
struct Edge {
	int to, next;
} edge[ESZ];

int t, dep[VSZ], fa[VSZ][MAXT]; //Ԥ����

bool isnew[VSZ]; //ÿ��ѯ��ǰ��Ҫ���
int must[2], mustnot[2]; //ÿ��ѯ��ǰ��Ҫ���
int64 f0[VSZ][2], f[VSZ][2], bcp[VSZ][2]; //f0ÿ��ѯ��ǰ�ָ�
int64 ans;

inline void addEdge(int x, int y) {
	static int tot = 0;
	edge[++tot].to = y;
	edge[tot].next = head[x], head[x] = tot;
}

void dfs0(int x) {
	dep[x] = dep[fa[x][0]] + 1;
	for (int i = 1; i <= t; i++)
		fa[x][i] = fa[ fa[x][i-1] ][i-1];
	for (int i = head[x]; i; i = edge[i].next) {
		int y = edge[i].to;
		if (y == fa[x][0])
			return;
		fa[y][0] = x;
		dfs0(y); 
	}
}

int Lca(int x, int y) {
	if (dep[x] < dep[y])
		std::swap(x, y);
	for (int i = t; i >= 0; i--)
		if (dep[ fa[x][i] ] >= dep[y])
			x = fa[x][i];
	if (x == y)
		return x;
	for (int i = t; i >= 0; i--)
		if (fa[x][i] != fa[y][i])
			x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}

void backup() {
	for (int i = 1; i <= n; i++)
		bcp[i][0] = f0[i][0], bcp[i][1] = f0[i][1];
}

void recover() {
	for (int i = 1; i <= n; i++)
		f0[i][0] = bcp[i][0], f0[i][1] = bcp[i][1];
}

void init() {
	must[0] = must[1] = mustnot[0] = mustnot[1] = 0;
	memset(isnew, 0, sizeof(isnew));
}

void dfs1(int x) {
	int64 tmp0 = 0, tmp1 = 0;
	for (int i = head[x]; i; i = edge[i].next) {
		int y = edge[i].to;
		if (y == fa[x][0])
			continue;
		dfs1(y);
		tmp0 += f0[y][1];
		if (tmp0 > INF - EPS)
			tmp0 = INF;
		tmp1 += min(f0[y][0], f0[y][1]);
		if (tmp1 > INF - EPS)
			tmp1 = INF;
	}
	tmp1 += v[x];
	if (x == must[0] || x == must[1]) //����פ�� 
		tmp0 = INF; //��פ������ΪINF 
	if (x == mustnot[0] || x == mustnot[1]) //����פ�� 
		tmp1 = INF; //פ������ΪINF 
	f0[x][0] = tmp0;
	f0[x][1] = tmp1;
}

void deflag(int x) {
	if (x == 0)
		return;
	isnew[x] = true;
	deflag(fa[x][0]);
}

void dfs2(int x) {
	if (!isnew[x]) {
		f[x][0] = f0[x][0], f[x][1] = f0[x][1];
		return;
	}
	int64 tmp0 = 0, tmp1 = 0;
	for (int i = head[x]; i; i = edge[i].next) {
		int y = edge[i].to;
		if (y == fa[x][0])
			continue;
		dfs2(y);
		tmp0 += f[y][1];
		if (tmp0 > INF - EPS)
			tmp0 = INF;
		tmp1 += min(f[y][0], f[y][1]);
		if (tmp1 > INF - EPS)
			tmp1 = INF;
	}
	tmp1 += v[x]; 
	f[x][0] = tmp0;
	f[x][1] = tmp1;
}

int main() {
//	freopen("defense.in", "r", stdin);
//	freopen("defense.out", "w", stdout);
	char tmp[3]; //���ò��� 
	scanf("%d%d%s", &n, &q, tmp);
	for (int i = 1; i <= n; i++)
		scanf("%d", v + i);
	for (int i = 1; i <= n - 1; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		addEdge(x, y), addEdge(y, x);
	}
	t = log2(n) + 1; //������LCA�������� 
	dfs0(1); //����Ԥ���� 
	dfs1(1); //�μ�Ԥ���� 
	for (int i = 1; i <= q; i++) {
		init(); //ÿ��ѯ��ǰ��ʼ�� 
		int a, b, x, y, lca;
		scanf("%d%d%d%d", &a, &x, &b, &y);
		if (x) //a����פ��
			must[0] = a;
		else //a����פ�� 
			mustnot[0] = a;
		if (y)
			must[1] = b;
		else
			mustnot[1] = b;
		backup(); //����f0���� 
		lca = Lca(a, b); //��LCA 
		dfs1(lca); //�������� 
		deflag(fa[lca][0]); //����Ҫ���µĽڵ���ϱ�ǣ���f0�������ŵĽڵ㣩 
		dfs2(1); //��dfs 
		ans = min(f[1][0], f[1][1]);
		if (ans > INF - EPS)
			puts("-1");
		else
			printf("%lld\n", ans);
		recover(); //�ָ�f0����
	}
	return 0;
}
