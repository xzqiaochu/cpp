/* nth_element 
时间复杂度 O(n) */
#include <cstdio>
#include <algorithm>
const int SZ = 107;

int n, k, a[SZ];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    scanf("%d", &k);
    std::nth_element(a + 1, a + k, a + n + 1); // 会对原数组进行修改
    printf("%d\n", a[k]);
    // a[k] 左边的元素均小于a[k]，右边的元素均大于a[k]
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    return 0;
}