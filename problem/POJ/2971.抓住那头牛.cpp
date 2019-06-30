#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int start, target, s[100001], ans;
bool visit[100001];

bool judge(int x) {
	if (x >= 0 && x <= 100000 && visit[x] == 0) return true;
	else return false;
}

void bfs() {
	queue <int> q;
	q.push(start);
	while(!q.empty()) {
		int temp = q.front();
		if (temp - 1 == target || temp + 1 == target || temp * 2 == target) {
			ans = s[temp] + 1;
			return;
		}
		q.pop();
		if (judge(temp - 1)) {
			visit[temp - 1] = 1;
			s[temp - 1] = s[temp] + 1;
			q.push(temp - 1);
		}
		if (judge(temp + 1)) {
			visit[temp + 1] = 1;
			s[temp + 1] = s[temp] + 1;
			q.push(temp + 1);
		}
		if (judge(temp * 2)) {
			visit[temp * 2] = 1;
			s[temp * 2] = s[temp] + 1;
			q.push(temp * 2);
		}
	}
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		memset(visit, 0, sizeof(visit));
		memset(s, 0, sizeof(s));
		cin >> start >> target;
		bfs();
		cout << ans << endl;
	}
	return 0;
}
