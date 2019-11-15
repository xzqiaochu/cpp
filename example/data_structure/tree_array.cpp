/* 树状数组
时间复杂度 单点修改/查询 O(log n)
空间复杂度 O(n) */
#include <cstdio>
const int SZ = 107;

int n, a[SZ];

void update(int x, int add) {
    for (; x <= n; x += x & -x)
        a[x] += add;
}

int ask(int x) {
    int rst = 0;
    for (; x; x -= x & -x)
        rst += a[x];
    return rst;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        update(i, i); // 建立树状数组（为了方便测试，这里省去了输入，初始把 a[i] 设置为 i）
    printf("%d\n", ask(n)); // 查询前缀和
    update(1, 2); // 把 a[1] 加上 2
    printf("%d", ask(n)); // 再次查询前缀和
    return 0;
}