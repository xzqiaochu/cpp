#include <iostream> 
#include <cstring>

#define maxn 100000000

using namespace std;

typedef long long int inttype;

bool isfit(char * str);
char * cut(char * str, inttype start, inttype end);

char list[maxn];
inttype fit[maxn];

int main() {
	inttype n, k, count = -1;
	cin >> n >> k >> list;
	for (inttype i = 0; i <= strlen(list) - 1; i++) {
		for (inttype j = i; j <= strlen(list) - 1; j++) {
			char * substr = cut(list, i, j);
			if (isfit(substr)) {
				count++;
				fit[count] = strlen(substr);
			}
			delete substr;
		}
	}
	if (count + 1 < k) {
		cout << -1;
		return 0;
	}
	inttype r = 0;
	for (inttype i = 1; i <= k; i++) {
		inttype temp = fit[0];
		inttype sign = 0;
		for (inttype j = 1; j <= count; j++) {
			if (fit[j] > temp) {
				temp = fit[j];
				sign = j;
			}
		}
		if (r == 0) {
			r = temp % 19930726;
		}else{
			r = r * temp % 19930726;
		}
		fit[sign] = 1;
	}
	cout << r;
	return 0;
}

bool isfit(char * str) {
	if (strlen(str) == 1) return true;
	if (strlen(str) % 2 == 0) return false; 
	for(inttype i = 0, j = strlen(str) - 1; i <= j; i++, j--) {
		if (str[i] != str[j]) return false;
	}
	return true;
}

char * cut(char * str, inttype start, inttype end) {
	char * p;
	p = new char[end - start + 2];
	for (inttype i = start, j = 0; i <= end; i++, j++) {
		p[j] = str[i];
	}
	p[end - start + 1] = 0;
	return p;
}
