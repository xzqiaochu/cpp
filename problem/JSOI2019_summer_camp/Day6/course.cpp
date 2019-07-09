// course
// author: xzqiaochu
// status: AC
#include <cstdio>
#include <cstring>
#include <algorithm>

typedef long long ll;

const int MAXN = 100007;

char s[MAXN];
int n, m, tm[26], ans1, ans2, C[30][30];

bool cmp(int x, int y)
{
	return x > y;
}

void initC()
{
	for (int i = 0; i <= 26; i++)
		C[i][0] = 1;
	for (int i = 1; i <= 26; i++)
		for (int j = 1; j <= i; j++)
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
}

int main()
{
	// freopen("course.in", "r", stdin);
	// freopen("course.out", "w", stdout);
	initC();
	scanf("%s%d", s, &m);
	n = strlen(s);
	for (int i = 0; i < n; i++)
		tm[s[i] - 'a']++;
	std::sort(tm, tm + 26, cmp);
	for (int i = 0; i < m; i++)
		ans1 += tm[i];
	int d = tm[m - 1], cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < 26; i++)
	{
		if (tm[i] < d)
			break;
		if (tm[i] == d)
			cnt2++;
		if (tm[i] == d && i < m)
			cnt1++;
	}
	ans2 = C[cnt2][cnt1];
	if (d == 0)
		printf("%d %d", ans1, 1);
	else
		printf("%d %d", ans1, ans2);
	return 0;
}