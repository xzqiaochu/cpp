# [NOIP2018]货币系统(money)

传送门：[洛谷P5020](https://www.luogu.org/problem/P5020) | [MFOJ](http://www.mfstem.org/contest/28/problem/B)
作者：[xzqiaochu](https://www.xzzhangqiaochu.top/)

---

## Solution

这是一道完全背包DP

新的货币系统 为 原货币系统删掉一些元素后的集合
而删除的元素满足的条件是 `可以被集合中其他元素线性表示`

设 $f[i][j]$ 表示处理到第 $i$ 个元素时，$j$ 元是否可以被表示

状态转移方程为

$$f[i][j] = f[i-1][j] \ | \ f[i-1][j-a[i]]$$

边界条件 $f[0] = true$，其余均为 $false$

具体步骤如下：

1. 把金额升序排序，设初始 $ans=n$
2. 从小到大开始 $dp$，如果发现 $a[i]$ 已经可以被表示，则跳过，并把 $ans$ 减去 $1$

## Code

```cpp
// B-货币系统(money)
// http://www.mfstem.org/contest/28/problem/B
// author: xzqiaochu
// status: AC
// time: 2019/11/02
#include <cstdio>
#include <cstring>
#include <algorithm>

const int NSZ = 107, MSZ = 25007;

int n, a[NSZ], f[MSZ];

int calc() {
	int ans = n;
	std::sort(a+1, a+n+1);
	memset(f, 0, sizeof(f));
	f[0] = true;
	for (int i = 1; i <= n; i++) {
		if (f[a[i]]) {
			ans--;
			continue;
		}
		for (int j = a[i]; j <= MSZ; j++)
			f[j] |= f[j-a[i]];
	}
	return ans;
}

int main() {
//	freopen("money.in", "r", stdin);
//	freopen("money.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", a + i);
		printf("%d\n", calc());
	}
	return 0;
}
```
