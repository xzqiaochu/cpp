# 动态规划 `2019.06.29`

## 0/1 背包

### 问题描述：容量为w的背包；一些 重量为price1，price2，price3...，价值为val1，val2，val3...物品；求装入背包物品的最大价值

### dp[i, j] 前i件物品供选择时，花费不超过j元 可以得到的最大价值

#### 初始化 dp[0, 0] = 0；其余负无穷

#### 目标 dp[n, w] // n为物品件数，w为背包容量

$$
dp[i, j] = \max
\begin{cases}
dp[i - 1, j] \\
dp[i - 1, j - price[i]] + val[i] & j - price[i] \ge 0
\end{cases}
$$

### 代码如下

```c++
for (int i = 1; i <= n; i++)
    for (int j = price[i]; j <= w; j++)
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - price[i]] + val[i]);
```

### 优化：滚动数组

```c++
for (int i = 1; i <= n; i++)
    for (int j = w; j >= w - price[i]; j--)
        dp[j] = max(dp[j], dp[j - price[i]] + val[i]);
```
