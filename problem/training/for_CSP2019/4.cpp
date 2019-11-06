// 简单毒瘤题 (dl.in/out)
// https://www.luogu.org/problem/P3556
// author: qiaochu(following Liu) 
// status: dev
// time: 2019/11/04
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long int64;
const int N = 2e5 + 7;
const int INF = 1e18;

int n, m, k, q;
int L[N], R[N], sec[N], wa[N], cnt;
int64 x[N][4], dp[N][4];

int main() {
	scanf("%d%d%d%d", &n, &m, &k, &q);
	//some bug
//	memset(L, 0x3f, sizeof(L)); 
	for (int i = 1; i < N; i++)
		L[i] = N;
	for (int i = 1; i <= k; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		L[x] = min(L[x], y);
		R[x] = max(R[x], y);
		wa[++cnt] = x; //毒瘤所在的阶段（行号） 
	}
	sort(wa + 1, wa + cnt + 1); //按行号排序 
	cnt = unique(wa + 1, wa + cnt + 1) - (wa + 1); //去重 
	for (int i = 1; i <= q; i++) //安全列 
		scanf("%d", sec + i);
	sort(sec + 1, sec + q + 1); //安全列排序 
	//特殊情况： 只有一行有毒瘤 
	if (cnt == 1) {
		int i = wa[1]; //取出所在行号 
		if (i == 1) //行号为1 
			printf("%d", R[i] - 1);
		else { //行号不为1 
			int step1 = sec[1] - 1; //到达最近安全通道
			int step2 = i - 1; //上升到目标行 
			int step3 = min(abs(sec[1]-L[i]), abs(sec[1]-R[i])); //到达目标行毒瘤区间端点 
			int step4 = R[i] - L[i]; //在目的行吃完毒瘤 
			int ans = step1 + step2 + step3 + step4;
			printf("%d", ans);
		}
		return 0;
	}
	//一般情况  
	//预处理 
	for (int i = 1; i <= cnt; i++) {
		int t = wa[i];
		int *t1 = lower_bound(sec+1, sec+q+1, L[i]);
		int *t2 = lower_bound(sec+1, sec+q+1, R[i]);
		x[i][0] = t1[-1];
		x[i][1] = t2[0];
		x[i][2] = t2[-1];
		x[i][3] = t2[0];
	}
	//第一个 
	for (int j = 0; j <= 3; j++) {
		int i = wa[1];//第一个毒瘤所在行号 
		dp[i][j] = INF;
		if (x[i][j]) {
			if (i == 1) { //如果是第一行 
				int step1 = R[i] - 1; //吃完毒瘤 
				int step2 = abs(x[i][j] - R[i]); //走到安全列，为下一次做准备 
				dp[i][j] = step1 + step2;
			}
			else {
				int try1 = abs(sec[1]-L[i]) + abs(x[i][j]-R[i]);
				int try2 = abs(sec[1]-R[i]) + abs(x[i][j]-L[i]);
				int step1 = min(try1, try2);
				int step2 = i - 1; //上升 
				int step3 = sec[i] - 1;
				int step4 = R[i] - L[i]; //吃毒瘤 
				dp[i][j] = step1 + step2 + step3 + step4; 
			}
		}
	}
	//第二个及之后的 
	for (int t = 2; t <= cnt; t++)
		for (int j = 0; j <= 3; j++) {
			int i = wa[t], ii = wa[t-1];
			dp[i][j] = INF;
			if (x[i][j])
				for (int k = 0; k <= 3; k++) {
					int step = min(dp[i][j], d[ii][k] + R[i] - L[i] + 
						min(abs(a[ii][k]-L[i]) + abs(x[i][j]-R[i])),
							abs(x[ii][k]-R[i]) + abs(x[i][j]-L[i])) +
							i - ii);
					dp[ii][k] = step;
				}
		}
	//统计答案 
	int64 ans = INF;
	for (int k = 0; k <= 3; k++) {
		int i = wa[cnt]; //当前毒瘤行号 
		int ii = wa[cnt-1]; //上一阶段毒瘤行号 
		int step1 = min(abs(x[ii][k]-L[i]), abs(x[ii][k]-R[i]));
		int step2 = i - ii;
		int step3 = R[i] - L[i];
		ans = min(ans, dp[ii][k] + step1 + step2 + step3);
	}
	printf("%lld", ans);
	return 0;
}
