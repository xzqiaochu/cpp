# 生活大爆炸版石头剪刀布(rps) `2019.07.20`

文章作者: xzqiaochu
题目出处: NOIP2014 Day1 Problem1
题目链接: [MFOJ](http://www.mfstem.org/contest/18/problem/A) [luogu](https://www.luogu.org/problemnew/show/P1328)

---

## Problem

### Description

石头剪刀布是常见的猜拳游戏：石头胜剪刀，剪刀胜布，布胜石头。如果两个人出拳一样，则不分胜负。在《生活大爆炸》第二季第8集中出现了一种石头剪刀布的升级版游戏。升级版游戏在传统的石头剪刀布游戏的基础上，增加了两个新手势：

斯波克：《星际迷航》主角之一。

蜥蜴人：《星际迷航》中的反面角色。

这五种手势的胜负关系如表一所示，表中列出的是甲对乙的游戏结果。

![石头剪刀布升级版胜负关系](http://www.mfstem.org/public/upload/46af6f9b10.png)

现在，小A和小B尝试玩这种升级版的猜拳游戏。已知他们的出拳都是有周期性规律的，但周期长度不一定相等。例如：如果小A以“石头-布-石头-剪刀-蜥蜴人-斯波克”长度为6的周期出拳，那么他的出拳序列就是“石头-布-石头-剪刀-蜥蜴人-斯波克-石头-布-石头-剪刀-蜥蜴人-斯波克-……”，而如果小B以“剪刀-石头-布-斯波克-蜥蜴人”长度为5的周期出拳，那么他出拳的序列就是“剪刀-石头-布-斯波克-蜥蜴人-剪刀-石头-布-斯波克-蜥蜴人-……”

已知小A和小B一共进行 $N$ 次猜拳。每一次赢的人得1分，输的得0分；平局两人都得0分。现请你统计 $N$ 次猜拳结束之后两人的得分。

### Input (读取文件: rps.in)

输入文件名为 rps.in。

第一行包含三个整数：$N$，$N_A$，$N_B$，分别表示共进行 $N$ 次猜拳、小A出拳的周期长度，小B出拳的周期长度。数与数之间以一个空格分隔。

第二行包含 $N_A$ 个整数，表示小A出拳的规律，第三行包含 $N_B$ 个整数，表示小B出拳的规律。其中，0表示“剪刀”，1表示“石头”，2表示“布”，3表示“蜥蜴人”，4表示“斯波克”。数与数之间以一个空格分隔。

### Output (写入文件: rps.out)

输出文件名为 rps.out。

输出一行，包含两个整数，以一个空格分隔，分别表示小A、小B的得分。

### Sample Input 1

10 5 6
0 1 2 3 4
0 3 4 2 1 0

### Sample Output 1

6 2

### Sample Input 2

9 5 5
0 1 2 3 4
1 0 3 2 4

### Sample Output 2

4 4

### Data

对于100%的数据，$0 < N ≤ 200$，$ 0 < N_A ≤ 200$，$0 < N_B ≤ 200$。

---

## Solution

模拟题
用一个二维字符数组储存pk结果

```cpp
const int SZ = 207;
// 0甲赢，1甲输，2平局
const char pk[5][6] =
{
    "21001",
    "02101",
    "10210",
    "11020",
    "00112"
};
```

然后for循环模拟即可

PS: 数组下标最好从0开始，因为这样取模方便

## Code

```cpp
// 生活大爆炸版石头剪刀布(rps) (http://www.mfstem.org/contest/18/problem/A)
// author: xzqiaochu
// status: AC
#include <cstdio>

const int SZ = 207;
// 0甲赢，1甲输，2平局
const char pk[5][6] =
{
    "21001",
    "02101",
    "10210",
    "11020",
    "00112"
};

int n, na, nb, a[SZ], b[SZ];
int cnta, cntb;

int main()
{
    freopen("rps.in", "r", stdin);
    freopen("rps.out", "w", stdout);
    scanf("%d%d%d", &n, &na, &nb);
    for (int i = 0; i < na; i++)
        scanf("%d", a + i);
    for (int i = 0; i < nb; i++)
        scanf("%d", b + i);
    for (int i = 0; i < n; i++)
    {
        if (pk[a[i % na]][b[i % nb]] == '0')
            cnta++;
        else if (pk[a[i % na]][b[i % nb]] == '1')
            cntb++;
    }
    printf("%d %d", cnta, cntb);
    return 0;
}
```
