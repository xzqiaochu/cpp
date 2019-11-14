// 全排列 - STL实现
#include <cstdio>
#include <algorithm>
const int SZ = 107;

int n, a[SZ];

int main() {
    a[4] = 100;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    std::sort(a + 1, a + n + 1); // 先排序
    do {
        for (int i = 1; i <= n; i++)
            printf("%d ", a[i]);
        puts("");
    } while (std::next_permutation(a + 1, a + n + 1));
    return 0;
}