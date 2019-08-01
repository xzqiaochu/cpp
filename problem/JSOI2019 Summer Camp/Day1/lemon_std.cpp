/* lemon AC
author: std */
#include <bits/stdc++.h>
int T, n;
int main(){
	freopen("lemon.in", "r", stdin);
	freopen("lemon.out", "w", stdout);
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		puts((n & (n - 1)) ? "No" : "Yes");
	}
	return 0;
}