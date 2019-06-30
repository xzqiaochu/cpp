#include <cstdio>
#include <map>

using namespace std;

map<int, int> a;

int main() {
	int n;
	scanf("%s", &n);
	for (int i = 0; i < n; i++) {
		int now;
		scanf("%s", &now);
		a[now]++;
	}
	map<int, int>::iterator iter;  
    for(iter = a.begin(); iter != a.end(); iter++) {
    	printf("%d %d", iter->first, iter->second);
	}
	return 0;
} 
