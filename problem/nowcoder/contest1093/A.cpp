// A-昂贵的字符串 
// https://ac.nowcoder.com/acm/contest/1093/A
// author: xzqiaochu
// status: AC
// time: 2019/11/03
#include <cstdio>
#include <cstring>
const int SZ = 1007;

bool t[27];
char s[SZ];
int a, b, len, cnt;

bool is_small(char c) {
	return c >= 'a' && c <= 'z';
}

void calc() {
	for (int i = 0; i < len; i++) {
		if (is_small(s[i]))
			t[s[i] - 'a' + 1] = true;
		else
			t[s[i] - 'A' + 1] = true;
	}
	if (a != b && t[a] && t[b]) //a可能等于b，太毒瘤了（虽然备注里说了） 
		t[b] = false;
	for (int i = 1; i <= 26; i++)
		if (t[i])
			cnt++; 
}

int main() {
	char tmpa[2], tmpb[2];
	scanf("%s%s%s", s, tmpa, tmpb);
	if (is_small(tmpa[0]))
		a = tmpa[0] - 'a' + 1;
	else
		a = tmpa[0] - 'A' + 1;
	if (is_small(tmpb[0]))
		b = tmpb[0] - 'a' + 1;
	else
		b = tmpb[0] - 'A' + 1;
	len = strlen(s);
	calc();
//	printf("%d", cnt);
	printf("%d", cnt * len);
	return 0;
}
