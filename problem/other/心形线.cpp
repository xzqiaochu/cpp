#include <iostream>
#include <cmath>

#define pi 3.14159

using namespace std;

char map[201][211] = {0};

int f1(int x) {
	double y = -tan(sqrt(1 - pow(fabs(x / 100 - 1), 1.5))) + pi / 2;
	return (int) 10 * y;
}

int main() {
	for (int i = 0; i <= 200; i++) map[i][f1(i)] = '*';
	for (int i = 0; i <= 200; i++) {
		for (int j = 0; j <= 210; j++) {
			cout << map[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
} 
