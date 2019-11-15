/* random_shuffle
随机打乱一个数组
可以用于骗分 */
#include <cstdio>
#include <ctime>
#include <algorithm>
const int SZ = 107;

int n, a[SZ];

int main() {
    // srand((unsigned)time(0));
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    std::random_shuffle(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    return 0;
}