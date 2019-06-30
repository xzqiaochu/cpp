#include <iostream>
#include <cstring>
#include <queue>
#include <map>

using namespace std;

char pro[4] = {-3, -1, 1, 3};
string st, tar;
queue <string> qa, qb;
map <string, int> v, s;

bool judge(int now_id, int Next_id) {
	if (Next_id < 0 || Next_id >= 9) return false;
	if (now_id == 2 && Next_id == 3) return false;
	if (now_id == 3 && Next_id == 2) return false;
	if (now_id == 5 && Next_id == 6) return false;
	if (now_id == 6 && Next_id == 5) return false;
	return true;
}

int bfs() {
	v[st] = 1;
	s[st] = 0;
	qa.push(st);
	v[tar] = 2;
	s[tar] = 0;
	qb.push(tar);
	while (!qa.empty() || !qb.empty()) {
		if (!qa.empty()) {
	    	string now = qa.front();
	    	qa.pop();
	        for (int now_id = 0; now_id < 9; now_id++) {
			    if (now[now_id] == '0') {
				    for (int k = 0; k < 4; k++) {
					    int Next_id = now_id + pro[k];
		    			if (judge(now_id, Next_id)) {
			    			string Next = now;
				    		Next[now_id] = Next[Next_id];
					    	Next[Next_id] = '0';
					    	if (v[Next] == 2) return s[now] + s[Next] + 1;
					    	if (v[Next] == 0) {
					    		v[Next] = 1;
					    		s[Next] = s[now] + 1;
			    			    qa.push(Next);
							}
		    				
			    		}
		    		}
			    	break;
	        	}
	        }
	    }
		if (!qb.empty()) {
	    	string now = qb.front();
	    	qb.pop();
	        for (int now_id = 0; now_id < 9; now_id++) {
			    if (now[now_id] == '0') {
				    for (int k = 0; k < 4; k++) {
					    int Next_id = now_id + pro[k];
		    			if (judge(now_id, Next_id)) {
			    			string Next = now;
				    		Next[now_id] = Next[Next_id];
					    	Next[Next_id] = '0';
					    	if (v[Next] == 1) return s[now] + s[Next] + 1;
					    	if (v[Next] == 0) {
					    		v[Next] = 2;
					    		s[Next] = s[now] + 1;
			    			    qb.push(Next);
							}
			    		}
		    		}
			    	break;
	        	}
	        }
	    }
    }
    return -1;
}

int main() {
	cin >> st;
	tar = "123804765";
	if (st == tar) cout << 0;
	else cout << bfs();
	return 0;
}
