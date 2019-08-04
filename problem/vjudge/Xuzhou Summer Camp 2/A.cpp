// A - Brackets Sequence (https://vjudge.net/contest/316500#problem/A)
// POJ 1141，ZOJ 1463，Ural 1183，UVA 2451
// from: ACM Northeastern Europe 2001
// author: xzqiaochu (Rewrite from the Internet)
// status: AC 
#include <cstdio>
#include <cstring>

const int SZ = 256, INF = 0x3f3f3f3f;

char s[SZ];
int f[SZ][SZ], pos[SZ][SZ];
int len;

void print_s(int i, int j) {
	if(i > j)
		return;
	if(i == j) {
		if(s[i] =='(' || s[j] == ')')
			printf("()");
		else
			printf("[]");
	} else if(pos[i][j] == -1) {
		printf("%c", s[i]);
		print_s(i+1, j-1);
		printf("%c", s[j]);
	} else {
		print_s(i, pos[i][j]);
		print_s(pos[i][j] + 1, j);
	}
}

bool match(int i, int j) {
	if(s[i] == '(' && s[j] == ')')
		return true;
	if(s[i] == '[' && s[j] == ']')
		return true;
	return false;
}

int main() {
	while (gets(s) != NULL) {
		memset(f, 0, sizeof(f));

		len = strlen(s);
		for (int i = 0; i < len; i++) // 边界
			f[i][i] = 1;

		for (int L = 1; L < len; L++) {
			for(int i = 0; i + L < len; i++) {
				int j = i + L;
				f[i][j] = INF;
				if(match(i, j)) { // 如果当前位置匹配，那么pos置-1
					f[i][j] = f[i+1][j-1] , pos[i][j] = -1;
				}
				for(int k = i; k < j; k++) {
					int temp = f[i][k] + f[k+1][j];
					if(temp < f[i][j]) { // 如果存在更优分解，那么选择更优分解
						f[i][j] = temp, pos[i][j] = k;
					}
				}
			}
		}
		print_s(0, len - 1);
		puts("");
	}
	return 0;
}
