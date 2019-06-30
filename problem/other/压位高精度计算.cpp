#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

typedef unsigned short unit;
typedef unsigned int cache;

void init(char a[], unit x[]) {
	char s[5];
	x[0] = (strlen(a) + 3) / 4;
    char *t = a + strlen(a);
    for (cache i = 1; i < x[0]; ++i) {
        strncpy(s, t -= 4, 4);
        sscanf(s, "%d", x + i);
    }
    int len = t - a;
    s[len] = 0;
    strncpy(s, a, len); 
    sscanf(s, "%d", x + x[0]);
}

unit * accadd(unit * a, unit * b) {
	cache a_len = a[0];
	cache b_len = b[0];
	unit * r = new unit[max(a_len, b_len) + 2];
	memset(r, 0, (max(a_len, b_len) + 2) * sizeof(unit));
	    cout << (max(a_len, b_len) + 2) * sizeof(unit) << endl;
	r[0] = max(a_len, b_len);
	for (cache i = 1; i <= max(a_len, b_len); i++) {
		cache temp = a[i] + b[i];
		if (temp >= pow(10, 4)) {
			temp = temp % (cache)pow(10, 4);
			r[i + 1] = 1;
			if (i == max(a_len, b_len)) r[0]++;
		}
		r[i] += temp;
	}
	return r;
}

int main() {
	char a_input_str[200], b_input_str[200];
	scanf("%s%s", a_input_str, b_input_str);
	unit a[200], b[200];
	init(a_input_str, a);
	init(b_input_str, b);
    unit * r = accadd(a, b);
    for (cache i = r[0]; i > 0; i--) printf("%04d", r[i]);
	return 0;
}
