//3-Ñ¡ÐÅ·â
//author: xzqiaochu
//status: std
//time: 2019/11/12
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
#include<vector>
#include<cstdlib>
#include<map>
#include<cmath>
using namespace std;

const int maxn = 600;

struct E {
	int u,v,use;
	E () {
		use = 0;
	}
} edgs[2*maxn];

struct EP {
	int v,p;
};

int n,i,j,fa[4*maxn],num[4*maxn],cur = 0,From[2*maxn],visp[4*maxn];
bool ok[2*maxn],vis[2*maxn],r[2*maxn];

vector <EP> vp[4*maxn];
vector <int> ve[2*maxn];
queue <int> q;

int father (int k) {
	return k == fa[k]?k:fa[k] = father(fa[k]);
}

bool Insert (int x) {
	int fu = father(edgs[x].u);
	int fv = father(edgs[x].v);
	if (fu == fv) return false;
	fa[fu] = fv;
	edgs[x].use = 1;
	return true;
}

bool dfs (int now,int to,int sy) {
	if (now == to) return true;
	visp[now] = sy;
	for (unsigned l = 0; l < vp[now].size(); l++) {
		int To = vp[now][l].v;
		if (visp[To] == sy) continue;
		int Num = vp[now][l].p;
		r[Num] = true;
		if (dfs(To,to,sy)) return true;
		r[Num] = false;
	}
	return false;
}

void Build (int x) {
	int l;
	memset(ok,false,sizeof(ok));
	memset(r,-1,sizeof(r));
	memset(visp,-1,sizeof(visp));
	for (l = 0; l <= x; l++) ve[l].push_back(l^1);
	for (l = 0; l <= x; l++)
		if (!edgs[l].use) {
			ok[l] = true;
			memset(r,false,sizeof(r));
			if (!dfs(edgs[l].u,edgs[l].v,l)) continue;
			ok[l] = false;
			for (j = 0; j < x; j++) if (r[j]) ve[l].push_back(j);
		}
}

bool bfs (int x) {
	memset(vis,false,sizeof(vis));
	memset(From,-1,sizeof(From));
	int end = -1;
	q.push(x);
	vis[x] = true;
	while (!q.empty()) {
		int k = q.front();
		q.pop();
		for (unsigned l = 0; l < ve[k].size(); l++) {
			int To = ve[k][l];
			if (vis[To]) continue;
			vis[To] = true;
			if ((edgs[To].use ^ edgs[k].use)) {
				From[To] = k;
				if (ok[To]) {
					end = To;
					while (!q.empty()) q.pop();
					break;
				}
				q.push(To);
			}
		}
	}
	if (end == -1) return false;
	for (; end != -1; end = From[end]) edgs[end].use ^= 1;
	return true;
}

void Clear() {
	for (j = 0; j <= cur; j++) fa[j] = j;
	for (j = 0; j < 4*n; j++) vp[j].clear();
	for (j = 0; j < 2*n; j++) ve[j].clear();
	for (j = 0; j < 2*i; j++)
		if (edgs[j].use) {
			fa[father(edgs[j].u)] = father(edgs[j].v);
			vp[edgs[j].u].push_back((EP) {
				edgs[j].v,j
			});
			vp[edgs[j].v].push_back((EP) {
				edgs[j].u,j
			});
		}
}

int main() {
//#ifndef ONLINE_JUDGE
//#ifndef YZY
//	freopen("game.in","r",stdin);
//	freopen("game.out","w",stdout);
//#else
//	freopen("yzy.txt","r",stdin);
//#endif
//#endif
	cin >> n;
	j = -1;
	for (i = 0; i < 2*n; i++) {
		scanf("%d%d",&edgs[i].u,&edgs[i].v);
		num[++j] = edgs[i].u;
		num[++j] = edgs[i].v;
	}
	sort (num,num + j + 1);
	for (i = 1; i <= j; i++)
		if (num[i] != num[i-1])
			num[++cur] = num[i];
	for (i = 0; i < 2*n; i++) {
		edgs[i].u = lower_bound(num,num + cur + 1,edgs[i].u) - num;
		edgs[i].v = lower_bound(num,num + cur + 1,edgs[i].v) - num;
	}
	for (i = 0; i < n; i++) {
		Clear();
		if (Insert(2*i)) continue;
		if (Insert(2*i+1)) continue;
		Build(2*i+1);
		if (bfs(2*i)) continue;
		bfs(2*i+1);
	}
	int ans = 0;
	for (i = 0; i < 2*n; i++)
		if (edgs[i].use)
			++ans;
	cout << ans;
	return 0;
}
