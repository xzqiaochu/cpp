// A-昂贵的字符串-std（牛客CSP-J入门组赛前集训营5）
// https://ac.nowcoder.com/acm/contest/1093/A
// author: Liu
// status: AC
// time: 2019/11/03
#include <cstdio>
#include <cctype>
const int N = 1007;
char s[N], s1[2], s2[2];
bool vis[30];
int main() {
	scanf("%s%s%s", s, s1, s2);
	s1[0] = tolower(s1[0]) - 'a', s2[0] = tolower(s2[0]) - 'a';
	int i, ans = 0;
	for (i = 0; s[i]; i++) {
		int tmp = tolower(s[i]) - 'a';
		if (tmp == s2[0])
			tmp = s1[0];
		if (not vis[tmp])
			++ans, vis[tmp] = true;
	}
	printf("%d", ans * i);
	return 0;
}
