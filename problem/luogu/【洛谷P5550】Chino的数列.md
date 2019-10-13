# 【洛谷P5550】Chino的数列

文章作者: xzqiaochu
题目出处: [洛谷P5550](https://www.luogu.org/problem/P5550)

---

## Solution

$k$ 的规模较大，暴力肯定是不行的
猜想这是一个周期性问题
具体步骤如下：

1. 保存初始状态，然后开始模拟
2. 如果发现有一个状态与 `初始状态` 相同，就找到了周期
3. 接下来求余数，再稍作计算即可

看到有的大佬用矩阵乘法做，实在想不明白，明明就是一道周期问题嘛

PS：题目中说 $k$ 可以达到 $10^{18}$，是要开 $long long$的，不过这题好像不开也能过

### Code

```cpp
// 洛谷P5550
// author: xzqiaochu
// status: AC
// time: 2019/10/13
#include <cstdio>
#include <algorithm>

typedef long long int64;

const int SZ = 87;

int n, s, m;
int64 k;
int64 a[SZ];
int64 ori[SZ];

void save()
{
    for (int i = 1; i <= n; i++)
        ori[i] = a[i];
}

void go()
{
    std::swap(a[s], a[m]);
    int64 temp = a[1];
    for (int i = 1; i <= n - 1; i++)
        a[i] = a[i + 1];
    a[n] = temp;
}

bool check()
{
    for (int i = 1; i <= n; i++)
        if (a[i] != ori[i])
            return false;
    return true;
}

void calc()
{
    int64 t = n;
    save();
    for (int64 i = 1; i <= k; i++)
    {
        go();
        if (check())
        {
            t = i;
            break;
        }
    }
    int64 rst = k % t;
    for (int64 i = 1; i <= rst; i++)
        go();
    for (int i = 1; i <= n; i++)
        printf("%lld ", a[i]);
}

int main()
{
    scanf("%d%d%d%lld", &n, &s, &m, &k);
    for (int i = 1; i <= n; i++)
        scanf("%lld", a + i);
    calc();
    return 0;
}

```
