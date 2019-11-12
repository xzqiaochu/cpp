//[NOIP2017]-Day1-B-ʱ�临�Ӷ�(complexity)
//http://www.mfstem.org/contest/26/problem/B
//author: xzqiaochu
//status: AC
//algorithm: ģ�� 
//time: 2019/11/12
#include <cstdio>
#include <cstring>
#include <stack>
using std::stack;
const int SZ = 107;

int L, O;
int now, maxn, pause;
bool is_err;
char f[2], com[2], from[2], to[2];
char vis[30];

struct Node {
	int val, ctb;
};
stack<Node> s;

void init() {
	maxn = 0, now = 0, pause = 0;
	is_err = false;
	memset(vis, 0, sizeof(vis));
	while (!s.empty())
		s.pop();
}

void fun1() {
	char ch = getchar();
	while (ch == ' ')
		ch = getchar();
	if (ch == 'n')
		from[0] = 'n';
	else {
		char tmp = getchar();
		if (tmp == ' ')
			from[0] = 0, from[1] = ch; //һλ�� 
		else
			from[0] = ch, from[1] = tmp; //��λ�� 
	}
}

void fun2() {
	char ch = getchar();
	while (ch == ' ')
		ch = getchar();
	if (ch == 'n')
		to[0] = 'n';
	else {
		char tmp = getchar();
		if (tmp == ' ')
			to[0] = 0, to[1] = ch; //һλ�� 
		else
			to[0] = ch, to[1] = tmp; //��λ�� 
	}
}

bool is_bigger() {
	return from[0] > to[0] || (from[0] == to[0] && from[1] > to[1]);
}

int main() {
//	freopen("complexity.in", "r", stdin);
//	freopen("complexity.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) {
		init();
		O = 0;
		scanf("%d O(n^%d)", &L, &O);
		char ch = 0;
		while (ch != '\r' && ch != '\n')
			ch = getchar();
		for (int i = 1; i <= L; i++) {
			scanf("%s", f);
			if (f[0] == 'E') { //��Ҫ��ջ
				if (s.empty()) { //ջ��Ϊ�գ���ջʧ��
					is_err = true;
					continue;
				}
				int val = s.top().val;
				int ctb = s.top().ctb;
				s.pop(), vis[val] = false;
				if (pause == 0) //δ���ֲ���ִ�е�ѭ����
					now -= ctb; //���µ�ǰʱ�临�Ӷ�
				if (ctb == -1)
					pause--;
			} else { //��Ҫ��ջ
				scanf("%s", com);
				fun1();
				fun2();
				if (vis[(int)(com[0] - 'a')]) { //ѭ�������ѱ�ռ��
					is_err = true;
					continue;
				}
				Node x;
				x.val = com[0] - 'a';
				//ѭ���޷�ִ��
				//1. n 1
				//1. 2 1
				if ((from[0] == 'n' && to[0] != 'n') || (from[0] != 'n' && to[0] != 'n' && is_bigger()))
					pause++, x.ctb = -1;
				else { //ѭ�������ִ��
					if (from[0] != 'n' && to[0] == 'n') //��ʱ�临�Ӷ��Ƿ��й��� 1 n
						x.ctb = 1; //�й���
					else
						x.ctb = 0;
				}
				s.push(x), vis[x.val] = true;
				if (pause == 0) { //δ���ֲ���ִ�е�ѭ����
					now += x.ctb; //��ǰʱ�临�Ӷ�
					maxn = std::max(maxn, now); //���´�
				}
			}
		}
		if (is_err || !s.empty())
			puts("ERR");
		else {
			if (O == maxn)
				puts("Yes");
			else
				puts("No");
		}
	}
	return 0;
}
