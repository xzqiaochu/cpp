# 联合权值(link) `2019.07.22`

文章作者: xzqiaochu
题目出处: NOIP2014 Day1 Problem2
题目链接: [MFOJ](http://www.mfstem.org/contest/18/problem/B) [luguo](https://www.luogu.org/problemnew/show/P1351)

---

## Problem

### Description

无向连通图 $G$ 有 $n$ 个点，$n-1$ 条边。点从 $1$ 到 $n$ 依次编号，编号为 $i$ 的点的权值为 $W_i$ ，每条边的长度均为 $1$ 。图上两点 $(u, v)$ 的距离定义为 $u$ 点到 $v$ 点的最短距离。对于图 $G$ 上的点对 $(u, v)$ ，若它们的距离为 $2$ ，则它们之间会产生 $W_u × W_v$ 的联合权值。

请问图 $G$ 上所有可产生联合权值的有序点对中，联合权值最大的是多少？所有联合权值之和是多少？

### Input (读取文件: $link.in$)

输入文件名为 $link.in$ 。

第一行包含 $1$ 个整数 $n$ 。

接下来 $n-1$ 行，每行包含 $2$ 个用空格隔开的正整数 $u$ 、 $v$ ，表示编号为 $u$ 和编号为 $v$ 的点之间有边相连。

最后 $1$ 行，包含 $n$ 个正整数，每两个正整数之间用一个空格隔开，其中第 $i$ 个整数表示图 $G$ 上编号为 $i$ 的点的权值为 $W_i$ 。

### Output (写入文件: $link.out$)

输出文件名为 $link.out$ 。

输出共 $1$ 行，包含 $2$ 个整数，之间用一个空格隔开，依次为图 $G$ 上联合权值的最大值和所有联合权值之和。

由于所有联合权值之和可能很大，输出它时要对 $10007$ 取余。

### Sample Input 1

5
1 2
2 3
3 4
4 5
1 5 2 3 10

### Sample Output 1

20 74

### Notice

![样例输入](http://www.mfstem.org/public/upload/2948cc8933.png)

本例输入的图如上所示，距离为2的有序点对有(1,3)、(2,4)、(3,1)、(3,5)、(4,2)、(5,3)。其联合权值分别为2、15、2、20、15、20。其中最大的是20，总和为74。

### Data

对于30%的数据，$1 < n ≤ 100$ ；

对于60%的数据，$1 < n ≤ 2000$ ；

对于100%的数据，$1 < n ≤ 200,000$，$0 < W_i ≤ 10,000$ 。

---

## Solution

### 最大求联合权值

1. 枚举每一个点
2. 遍历与该点相连的点，找最大值 $max1$ 和次大值 $max2$，具体代码如下

```cpp
int max1 = 0, max2 = 0;
for (int i = head[x]; i; i = edge[i].next)
{
    int y = edge[i].y;
    if (w[y] > max1)
    {
        max2 = max1;
        max1 = w[y];
    } else if (w[y] > max2)
        max2 = w[y];
}
ans1 = max(ans1, max1 * max2);
```

用 $max1 * max2$ 更新答案

### 求联合权值之和

注意到 $(a + b + c)^2 = a^2 + b^2 + c ^ 2 + 2ab + 2ac + 2bc$
所以枚举每个点时，只需统计与该点相连的点的

- 和的平方
- 平方和

代码如下

```cpp
int sum = 0, sqrs = 0;
for (int i = head[x]; i; i = edge[i].next)
{
    int y = edge[i].y;
    sum = (sum + w[y]) % P;
    sqrs = (sqrs + w[y] * w[y]) % P;
}
ans2 = (ans2 + sum * sum - sqrs) % P;
```

在目前答案上累加 (和的平方 - 平方和)
PS: 因为题目中描述为 `有序点对`，所以不需除以2

## Code

```cpp
// 联合权值(link) (http://www.mfstem.org/contest/18/problem/B)
// author: xzqiaochu
// status: AC
#include <cstdio>
#include <algorithm>

using std::max;

const int SZP = 2e5 + 7, SZE = 2 * SZP, P = 10007;

int n;
int w[SZP];
struct Edge
{
    int x, y, next;
    Edge() {}
    Edge(int _x, int _y, int _n) : x(_x), y(_y), next(_n) {}

} edge[SZE];
int head[SZP];
int ans1, ans2;

inline void addEdge(int x, int y)
{
    static int tot;
    edge[++tot] = Edge(x, y, head[x]);
    head[x] = tot;
}

int main()
{
    // freopen("link.in", "r", stdin);
    // freopen("link.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        addEdge(x, y), addEdge(y, x);
    }
    for (int i = 1; i <= n; i++)
        scanf("%d", w + i);

    for (int x = 1; x <= n; x++)
    {
        int max1 = 0, max2 = 0;
        int sum = 0, sqrs = 0;
        for (int i = head[x]; i; i = edge[i].next)
        {
            int y = edge[i].y;
            if (w[y] > max1)
            {
                max2 = max1;
                max1 = w[y];
            } else if (w[y] > max2)
                max2 = w[y];
            sum = (sum + w[y]) % P;
            sqrs = (sqrs + w[y] * w[y]) % P;
        }
        ans1 = max(ans1, max1 * max2);
        ans2 = (ans2 + sum * sum - sqrs) % P;
    }

    printf("%d %d", ans1, ans2);
    return 0;
}
```
