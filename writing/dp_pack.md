# 背包动态规划 `2019.07.08`

## 1. 0/1 背包(ZeroOnePack)

### Problem

有 $N$ 件物品和一个容量为 $V$ 的背包。第 $i$ 件物品的费用（即体积，下同）是 $w_i$ ，价值是 $c_i$ 。求解将哪些物品装入背包可使这些物品的费用总和不超过背包容量，且价值总和最大。

### Solution

$f[i, v]$ 表示 前 $i$ 件物品供选择时，花费（恰好/不超过）$v$ 可以得到的最大价值

初始化

- 若要求背包装满：$f[0] = 0, f[1..V] = -∞$
- 若不要求背包装满：$f[0..V] = 0$

目标

- $f[N, V]$ $N$ 为物品件数，$V$ 为背包容量

$$
f[i, v] = \max
\begin{cases}
f[i - 1, v] \\
f[i - 1, v - w[i]] + c[i]  &  v - v[i] ≥ 0
\end{cases}
$$

- 时间复杂度 $O(VN)$

### Code

```c++
for (int i = 1; i <= N; i++)
    for (int v = w[i]; v <= V; j++)
        f[i][v] = max(f[i - 1][v], f[i - 1][v - w[i]] + c[i]);
```

- 时间复杂度 $O(VN)$
- 空间复杂度 $O(VN)$

#### Optimization：滚动数组

```c++
for (int i = 1; i <= N; i++)
    for (int j = v; j >= w[i]; j--)
        f[j] = max(f[j], f[j - w[i]] + c[i]);
```

- 时间复杂度 $O(VN)$
- 空间复杂度 $O(V)$

#### Model

```c++
void ZeroOnePack(int cost, int val)
{
    for (int v = V; v >= cost; v--)
        f[v] = max(f[v], f[v - cost] + val);
}

// 调用
for (int i = 1; i <= N; i++)
    ZeroOnePack(w[i], c[i]);
```

- 时间复杂度 $O(VN)$
- 空间复杂度 $O(V)$

## 2. 完全背包(CompletePack)

### Problem

有 N 种物品和一个容量为 V 的背包，每种物品都有无限件可用。第 $i$ 种物品的费用是 $w_i$ ，价值是 $c_i$ 。求解将哪些物品装入背包可使这些物品的费用总和不超过背包容量，且价值总和最大。

### Solution

$$
f[i, v] = \max
\{ f[i - 1, v - k * w[i]] + k * c[i] \}
$$

可转化为

$$
f[i, v] = \max
\begin{cases}
f[i - 1, v] \\
f[i, v - w[i]] + c[i]  &  v - w[i] ≥ 0
\end{cases}
$$

### Code

```c++
for (int i = 1; i <= N; i++)
    for (int v = w[i]; j <= V; v++)
        f[v] = max(f[v], f[v - w[i]] + c[i]);
```

- 时间复杂度：$O(VN)$
- 空间复杂度：$O(V)$

两层for循环次序可以颠倒

#### Model

```c++
void CompletePack(int cost, int val)
{
    for (int v = cost; v <= V; v++)
        f[v] = max(f[v], f[v - cost] + val);
}

// 调用
for (int i = 1; i <= N; i++)
    CompletePack(w[i], c[i]);
```

- 时间复杂度：$O(VN)$
- 空间复杂度：$O(V)$

## 3. 多重背包问题(MultiplePack)

### Problem

有 $N$ 种物品和一个容量为 $V$ 的背包。第 $i$ 种物品最多有 $a_i$ 件可用，每件费用是 $w_i$ ，价值是 $c_i$ 。求解将哪些物品装入背包可使这些物品的费用总和不超过背包容量，且价值总和最大。

### Solution

#### 1. 基本算法

$$
f[i, v] = \max
\{ f[i - 1, v - k * w[i]] + k * c[i] \}
$$

- 时间复杂度: $O(V\sum_{i = 1}^N a_i)$

#### 2. 转化为0/1背包

把第 $i$ 种物品换成 $a_i$ 件0/1背包中的物品，则得到了物品数为 $\sum_{i = 1}^N a_i$ 的0/1背包问题，直接求解

- 时间复杂度: $O(V\sum_{i = 1}^N a_i)$

#### 3. 二进制拆分

e.g. 如果 $n_i$ 为 $13$ ，就将这种物品分成系数分别为 $1,2,4,6$ 的四件物品

- 时间复杂度: $O(V\sum_{i = 1}^N log\ a_i)$

#### 4. 单调队列优化

- 时间复杂度: $O(VN)$

### Code

二进制拆分法

```c++
void MultiplePack(int cost, int val, int amount)
{
    if (cost * amount >= V)
    {
        CompletePack(cost, val);
        return;
    }
    for (int k = 1; k < amount; amount -= k, k *= 2) // 1,2,4
        ZeroOnePack(k * cost, k * val);
    ZeroOnePack(amount * cost, amount * val); // 6
}

// 调用
for (int i = 1; i <= N; i++)
    MultiplePack(w[i], c[i], a[i]);
```

- 时间复杂度: $O(V\sum_{i = 1}^N log\ a_i)$
- 时间复杂度: $O(V)$

## 4. 混合三种背包问题

### Code

```c++
for (int i = 1; i <= N; i++)
    if 第i件物品属于0/1背包
        ZeroOnePack(c[i], w[i]);
    else if 第i件物品属于完全背包
        CompletePack(c[i], w[i]);
    else if 第i件物品属于多重背包
        MultiplePack(c[i], w[i], a[i]);
```
