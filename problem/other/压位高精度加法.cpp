//���ӣ�ѹλ�߾��ӷ�-ÿ4λ����һ��intԪ�أ���10000��λ
#include <cstdio>
#include <cstring>
char a[210], b[210], s[5];
int x[55], y[55], i;
const int BASE = 10000;
inline int max(int &a, int &b) {
    return a >= b ? a : b;
}
void init(char a[], int x[]) {
    char *t = a + strlen(a);
    for (int i = 1; i < x[0]; ++i) {
        strncpy(s, t -= 4, 4);
        sscanf(s, "%d", x + i);
    }
    int len = t - a;
    s[len] = 0;
    strncpy(s, a, len); 
    sscanf(s, "%d", x + x[0]);
}
int main() {
    scanf("%s%s", a, b);
    //������ĵ�0��Ԫ�ش洢�ô���������λ��
    x[0] = (strlen(a) + 3) / 4;
    y[0] = (strlen(b) + 3) / 4;
    init(a, x), init(b, y);
    x[0] = max(x[0], y[0]) + 1;
    for (int i = 1; i <= x[0]; ++i)
        x[i] += y[i], x[i+1] += (x[i]>=BASE), x[i] %= BASE;
    while (!x[ x[0] ] && x[0]>1) --x[0];
    printf("%d", x[ x[0] ]);
    for (int i = x[0] - 1; i > 0; --i)
        printf("%04d", x[i]);
    printf("\n");
    return 0;
}

