# 背包动态规划 `2019.07.04`

## 0/1 背包

### Problem

有 $N$ 件物品和一个容量为 $M$ 的背包。第 $i$ 件物品的费用（即体积，下同）是 $w_i$ ，价值是 $c_i$ 。求解将哪些物品装入背包可使这些物品的费用总和不超过背包容量，且价值总和最大。

### Solution

$f[i, j]$ 表示 前 $i$ 件物品供选择时，花费（恰好/不超过）j 可以得到的最大价值

初始化

- 若要求背包装满：$f[0] = 0, f[1..n] = -∞$
- 若不要求背包装满：$f[0..n] = 0$

目标

- $f[n, m]$ $n$ 为物品件数，$m$ 为背包容量

$$
f[i, j] = \max
\begin{cases}
f[i - 1, j] \\
f[i - 1, j - w[i]] + c[i]  &  j - w[i] ≥ 0
\end{cases}
$$

- 时间复杂度 $O(nm)$

### Code

```c++
for (int i = 1; i <= n; i++)
    for (int j = w[i]; j <= m; j++)
        f[i][j] = max(f[i - 1][j], f[i - 1][j - w[i]] + c[i]);
```

- 空间复杂度 $O(nm)$

#### Optimization：滚动数组

```c++
for (int i = 1; i <= n; i++)
    for (int j = m; j >= w[i]; j--)
        f[j] = max(f[j], f[j - w[i]] + c[i]);
```

- 空间复杂度 $O(m)$

## 完全背包

### Problem

有 N 9/*种物品和一个容量为 M 的背包，每种物品都有无限件可用。第i种物品的费用是 $w_i$ ，价值是 $c_i$ 。求解将哪些物品装入背包可使这些物品的费用总和不超过背包容量，且价值总和最大。

### Solution

$$
f[i, j] = \max
\{ f[i - 1, j - k * w[i]] + k * c[i] \} | 0 <= k * c[i] <= m
$$

可转化为

$$
f[i, j] = \max
\begin{cases}
f[i - 1, j] \\
f[i, j - w[i]] + c[i]  &  j - w[i] ≥ 0
\end{cases}
$$

Code

```c++
for (int i = 1; i <= n; i++)
    for (int j = w[i]; j <= m; j++)
        f[j] = max(f[j], f[j - w[i]] + c[i]);
```

- 时间复杂度：$O(nm)$
- 空间复杂度：$O(m)$

两层for循环次序可以颠倒
