//特殊集合
#include <cstdio>
#include <queue>

using namespace std;

int n;
queue<int> q1, q2;

int bfs() {
	q1.push(1);
	q2.push(1);
	for (int i = 1; i <= n; i++) {
		int now = 0;
		if (now == 0) {
			if (q1.front() < q2.front()) {
				now = q1.front();
				q1.pop();
			} else if (q1.front() > q2.front()) {
				now = q2.front();
				q2.pop();
			} else {
				now = q1.front();
				q1.pop();
				q2.pop();
			}
		}
		if (i == n)
			return now;
		q1.push(now * 2 + 1);
		q2.push(now * 3 + 1);
	}
}

int main() {
	scanf("%d", &n);
	printf("%d", bfs());
	return 0;
}