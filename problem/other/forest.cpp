#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int l, n;
bool found;

struct des_struct {
	int num[2];
	bool sta[2];
} des[100001];

map <int, bool> list;

void bfs(int now, int s) {
	if (found == true) return;
	if (now == n && s == l) {
		found = true;
		map <int, bool>::iterator iter;
        for (iter = list.begin(); iter != list.end(); iter++) {
    	    if (iter -> second == 0) putchar('G');
			else if (iter -> second == 1) putchar('P');
	    }
		return;
	}
	if (now < n) {
		for (int i = 0; i <= 1; i++) {
		    int next_num = des[now + 1].num[i];
		    bool next_sta = des[now + 1].sta[i];
		    if(list.find(next_num) == list.end()) { //未选过next_num
		    	list[next_num] = next_sta;
		    	bfs(now + 1, s + 1);
		    	list.erase(next_num);
	    	} else {
		    	if (list[next_num] == next_sta) { //已选过next_num，但不矛盾
		    	    bfs(now + 1, s);
			    }
	    	}
    	}
	}
}

int main() {
	cin >> l >> n;
	for (int i = 1; i <= n; i++) {
		char temp_sta1_c, temp_sta2_c;
		scanf("%d %c %d %c", &des[i].num[0], &temp_sta1_c, &des[i].num[1], &temp_sta2_c);
		if (temp_sta1_c == 'P') des[i].sta[0] = true;
		else if (temp_sta1_c == 'G') des[i].sta[0] = false;
		if (temp_sta2_c == 'P') des[i].sta[1] = true;
		else if (temp_sta2_c == 'G') des[i].sta[1] = false;
	}
//	for (int i = 1; i <= n; i++) {
//		printf("%d %d %d %d\n", des[i].num[0], des[i].sta[0], des[i].num[1], des[i].sta[1]);
//	}
    bfs(0, 0); 
	return 0;
}
