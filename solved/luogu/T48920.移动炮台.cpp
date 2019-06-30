#include <bits/stdc++.h>

using namespace std;

struct m_struct {
	int x, y;
} m;

struct man_struct {
	int x, y;
	short int dis;
} man;

struct pao_struct {
	int x;
	bool dis;
} pao;

struct dan_struct {
	int x, y, ttf;
	short int dis;
} dan;

void reman() {
	switch (man.dis) {
		case 0 :
			if (man.x == 1) {
				man.dis = 1;
				man.x++;
			} else {
				man.x--;
			}
			break;
		case 1 :
			if (man.x == m.x) {
				man.dis = 0;
				man.x--;
			} else {
				man.x++;
			}
			break;
		case 2 :
			if (man.y == 1) {
				man.dis = 3;
				man.y++;
			} else {
				man.y--;
			}
			break;
		case 3 :
			if (man.y == m.y) {
				man.dis = 2;
				man.y--;
			} else {
				man.y++;
			}
			break;
	}
}

void repao() {
	if (pao.dis && pao.x == 1) {
		pao.dis = false;
	}
	if (!pao.dis && pao.x == m.x) {
		pao.dis = true;
	}
	if (pao.dis) pao.x--;
	else pao.x++;
}

void redan() {
	bool outx, outy;
	switch (dan.dis) {
		case 0 :
a :
			outx = dan.x == 1;
			outy = dan.y == m.y;
			if (outx && !outy) {
				dan.dis = 3;
				dan.ttf--;
				goto d;
			} else if (!outx && outy) {
				dan.dis = 2;
				dan.ttf--;
				goto c;
			} else if (outx && outy) {
				dan.dis = 1;
				dan.ttf--;
				goto b;
			} else {
				dan.x--;
				dan.y++;
			}
			break;
		case 1 :
b :
			outx = dan.x == m.x;
			outy = dan.y == 1;
			if (outx && !outy) {
				dan.dis = 2;
				dan.ttf--;
				goto c;
			} else if (!outx && outy) {
				dan.dis = 3;
				dan.ttf--;
				goto d;
			} else if (outx && outy) {
				dan.dis = 0;
				dan.ttf--;
				goto a;
			} else {
				dan.x++;
				dan.y--;
			}
			break;
		case 2 :
c :
			outx = dan.x == 1;
			outy = dan.y == 1;
			if (outx && !outy) {
				dan.dis = 1;
				dan.ttf--;
				goto b;
			} else if (!outx && outy) {
				dan.dis = 0;
				dan.ttf--;
				goto a;
			} else if (outx && outy) {
				dan.dis = 3;
				dan.ttf--;
				goto d;
			} else {
				dan.x--;
				dan.y--;
			}
			break;
		case 3 :
d :
			outx = dan.x == m.x;
			outy = dan.y == m.y;
			if (outx && !outy) {
				dan.dis = 0;
				dan.ttf--;
				goto a;
			} else if (!outx && outy) {
				dan.dis = 1;
				dan.ttf--;
				goto b;
			} else if (outx && outy) {
				dan.dis = 2;
				dan.ttf--;
				goto c;
			} else {
				dan.x++;
				dan.y++;
			}
			break;
	}
}

void shot(int k) {
	dan.x = pao.x;
	dan.y = 1;
	dan.ttf = k;
	dan.dis = pao.dis ? 0 : 3;
}

bool check() {
	if (dan.x == man.x && dan.y == man.y) return true;
	else return false;
}

//char mmap[6][6];
//
//void mp(int i) {
//	memset(mmap, '0', sizeof(mmap));
//	mmap[pao.x][1] = '#';
//	mmap[dan.x][dan.y] = '@';
//	mmap[man.x][man.y] = '$';
//	system("cls");
//	cout << i << endl;
//	for (int i = 1; i <= 5; i++) {
//		for (int j = 1; j <= 5; j++) {
//			cout << mmap[i][j] << ' ';
//		}
//		cout << endl;
//	}
//	cout << endl;
//	system("pause");
//}

int main() {
	int k;
	cin >> m.x >> m.y >> man.x >> man.y >> k >> man.dis;
	pao.x = m.x;
	pao.dis = true;
	bool die = false;
	int i = 0;
	for (; i < 1000; i++) {
		if ((pao.x == 1 || pao.x == m.x) && i != 0) {
			repao();
		}
		shot(k);
		while (dan.ttf >= 0) {
//			mp(i);
			if (check()) {
				die = true;
				break;
			}
			redan();
		}
		if (die) break;
		reman();
		repao();
	}
	if (die) {
		if (i == 0) {
			cout << 0;
		} else {
			cout << pao.x << ' ' << 1 << endl;
			cout << man.x << ' ' << man.y << endl;
			cout << i;
		}
	} else {
		cout << "Niubi";
	}
	return 0;
}
