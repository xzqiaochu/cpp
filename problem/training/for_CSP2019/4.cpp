// �򵥶����� (dl.in/out)
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
		wa[++cnt] = x; //�������ڵĽ׶Σ��кţ� 
	}
	sort(wa + 1, wa + cnt + 1); //���к����� 
	cnt = unique(wa + 1, wa + cnt + 1) - (wa + 1); //ȥ�� 
	for (int i = 1; i <= q; i++) //��ȫ�� 
		scanf("%d", sec + i);
	sort(sec + 1, sec + q + 1); //��ȫ������ 
	//��������� ֻ��һ���ж��� 
	if (cnt == 1) {
		int i = wa[1]; //ȡ�������к� 
		if (i == 1) //�к�Ϊ1 
			printf("%d", R[i] - 1);
		else { //�кŲ�Ϊ1 
			int step1 = sec[1] - 1; //���������ȫͨ��
			int step2 = i - 1; //������Ŀ���� 
			int step3 = min(abs(sec[1]-L[i]), abs(sec[1]-R[i])); //����Ŀ���ж�������˵� 
			int step4 = R[i] - L[i]; //��Ŀ���г��궾�� 
			int ans = step1 + step2 + step3 + step4;
			printf("%d", ans);
		}
		return 0;
	}
	//һ�����  
	//Ԥ���� 
	for (int i = 1; i <= cnt; i++) {
		int t = wa[i];
		int *t1 = lower_bound(sec+1, sec+q+1, L[i]);
		int *t2 = lower_bound(sec+1, sec+q+1, R[i]);
		x[i][0] = t1[-1];
		x[i][1] = t2[0];
		x[i][2] = t2[-1];
		x[i][3] = t2[0];
	}
	//��һ�� 
	for (int j = 0; j <= 3; j++) {
		int i = wa[1];//��һ�����������к� 
		dp[i][j] = INF;
		if (x[i][j]) {
			if (i == 1) { //����ǵ�һ�� 
				int step1 = R[i] - 1; //���궾�� 
				int step2 = abs(x[i][j] - R[i]); //�ߵ���ȫ�У�Ϊ��һ����׼�� 
				dp[i][j] = step1 + step2;
			}
			else {
				int try1 = abs(sec[1]-L[i]) + abs(x[i][j]-R[i]);
				int try2 = abs(sec[1]-R[i]) + abs(x[i][j]-L[i]);
				int step1 = min(try1, try2);
				int step2 = i - 1; //���� 
				int step3 = sec[i] - 1;
				int step4 = R[i] - L[i]; //�Զ��� 
				dp[i][j] = step1 + step2 + step3 + step4; 
			}
		}
	}
	//�ڶ�����֮��� 
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
	//ͳ�ƴ� 
	int64 ans = INF;
	for (int k = 0; k <= 3; k++) {
		int i = wa[cnt]; //��ǰ�����к� 
		int ii = wa[cnt-1]; //��һ�׶ζ����к� 
		int step1 = min(abs(x[ii][k]-L[i]), abs(x[ii][k]-R[i]));
		int step2 = i - ii;
		int step3 = R[i] - L[i];
		ans = min(ans, dp[ii][k] + step1 + step2 + step3);
	}
	printf("%lld", ans);
	return 0;
}
