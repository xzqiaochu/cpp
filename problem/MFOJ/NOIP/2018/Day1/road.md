## 【NOIP2018】铺设道路(road)

传送门：[洛谷P5019](https://www.luogu.org/problem/P5019) | [MFOJ](http://www.mfstem.org/contest/28/problem/A)
作者：xzqiaochu

---

### Solution

观察样例，递归求解即可

1. 求出 `区间[1, n]` 中的最小值 `minn`
2. 把区间里的每一个数均减去 `minn`
3. 这时，区间被 $0$ 划分成了若干个部分，递归求解每个部分即可

注意：

- 递归要先写边界
- 看清题目是 `标准输入输出` 还是 `文件输入输出`

### Code

```cpp
// A-铺设道路(road)
// http://www.mfstem.org/contest/28/problem/A
// author: xzqiaochu
// status: AC
// time: 2019/10/31
#include <cstdio>
#include <algorithm>

using std::min;

const int SZ = 1e5 + 7;
const int INF = 0x3f3f3f3f;

int n, a[SZ];
int ans;

void work(int l, int r)
{
	if (l == r)
	{
		ans += a[l];
		return;
	}
	int minn = INF;
	for (int i = l; i <= r; i++)
		minn = min(minn, a[i]);
	ans += minn;

	for (int i = l; i <= r; i++)
		a[i] -= minn;

	int p = l;
	while (1)
	{
		while (p <= r && a[p] == 0)
			p++; // p != 0
		if (p == r + 1)
			break;
		int st = p;
		while (p <= r && a[p] != 0)
			p++; // p = 0
		if (p == r + 1)
		{
			work(st, r);
			break;
		}
		work(st, p - 1);
	}
}

int main()
{
//	freopen("road.in", "r", stdin);
//	freopen("road.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	work(1, n);
	printf("%d", ans);
	return 0;
}
```
