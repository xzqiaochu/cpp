# 背包动态规划 `2019.07.03`

## 0/1 背包

### Problem

有N件物品和一个容量为M的背包。第i件物品的费用（即体积，下同）是w[i]，价值是c[i]。求解将哪些物品装入背包可使这些物品的费用总和不超过背包容量，且价值总和最大。

### Solution

$dp[i, j]$ 前i件物品供选择时，花费不超过j 可以得到的最大价值

初始化 $dp[0, 0] = 0$；其余负无穷
目标 $dp[n, m]$ n为物品件数，m为背包容量

$$
dp[i, j] = \max
\begin{cases}
dp[i - 1, j] \\
dp[i - 1, j - w[i]] + c[i] & j - w[i] \ge 0
\end{cases}
$$

时间复杂度O(nm)

### Code

```c++
for (int i = 1; i <= n; i++)
    for (int j = w[i]; j <= m; j++)
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + c[i]);
```

空间复杂度O(nm)

#### Optimization：滚动数组

```c++
for (int i = 1; i <= n; i++)
    for (int j = m; j >= w[i]; j--)
        dp[j] = max(dp[j], dp[j - w[i]] + c[i]);
```

空间复杂度O(m)
