# JSOI2019 Summer Camp `Day1`

## lemon `1s/256MB`

### Problem

#### Background

Jerry 在舔柠檬，一片柠檬可以看作是一个被分成若干格扇形的圆。Jerry 有自己喜爱的舔柠檬方式，逆时针舔，第一次舔第一格，第二次舔下一格，第三次舔跳过一格，第四次舔跳过两格…… Jerry 想知道这样舔下去能否舔到柠檬的所有扇形，但是 Jerry 沉迷于享受舔柠檬的快乐，就把这个任务交给你了。

#### Description

Jerry 的柠檬有 n 格扇形。第 k 次舔的格子会在第 k-1 次的基础上逆时针跳过 k-2 格，即逆时针方向第 k-1 格。请告诉 Jerry，一直不停地舔下去是否能舔到所有的格子。

#### Input

第一行一个正整数 T，表示有 T 组数据。
接着 T 行每行一个正整数 n，表示柠檬的格数。

#### Output

对于每组数据，输出一行一个字符串，其中能舔到所有格子输出“Yes”，反之输出“No”。（都不带双引号）

#### Sample Input 1

2
1
2

#### Sample Output 1

Yes
Yes

#### Sample Input 2

2
233
666

#### Sample Output 2

No
No

#### Data

对于20%的数据，$T≤5，n≤10$。
对于40%的数据，$T≤20，n≤100$。
对于70%的数据，$T≤200，n≤10^5$。
对于100%的数据，$1≤T≤1000，1≤n≤10^9$。

### Solution

打表可发现，当且仅当$n=2^k$时有解

### Code

```c++
/* lemon AC
author: std */
#include <bits/stdc++.h>
int T, n;
int main(){
	// freopen("lemon.in", "r", stdin);
	// freopen("lemon.out", "w", stdout);
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		puts((n & (n - 1)) ? "No" : "Yes");
	}
	return 0;
}
```

## helpers `1s/256MB`

### Problem

#### Background

Jerry 为了对抗 Tom，找来了一些帮手，Jerry 想先通过比武来决出最强的一位，以确保面对 Tom 时有更大的胜算。Jerry 想知道每个帮手胜出的可能性，但是还要去负责组织比武，就把这个任务交给你了。

#### Description

Jerry 有 n 个帮手，每个帮手有个初始积分ܽ݅，现在进行若干轮比武，每轮比武选择两个未被淘汰的帮手，获胜的帮手积分+1，落 败的帮手积分-1，如果一个帮手积分变成了 0 则自动淘汰。比武会一直进行，直到最后只剩下一个帮手。已知参加每轮比武的帮手由 Jerry 随机抽选，而每轮比武时双方胜出的概率都为 50%，你要告诉 Jerry 最后每个帮手胜出的概率。

#### Input

第一行 1 个正整数 n，表示帮手个数。
第二行有 n 个正整数，表示每个帮手的初始积分。

#### Output

一行 n 个整数，表示每个帮手最后胜出的概率对 998244353 取模后的结果。

#### Sample Input 1

1
233

#### Sample Output 1

1

#### Sample Input 2

3
1 1 1

#### Sample Output 2

332748118 332748118 332748118

#### Data

对于10%的数据，$n=1$。
对于另外30%的数据，$n=2$。
对于另外20%的数据，$a_i=1$。
对于100%的数据，$1≤n≤10^7，1≤∑a_i≤998244352$。

### Solution

答案为$a_i*sum^{p-2}$

证明如下

设$f_i$表示分数为$a_i$人获胜的概率，则有

$$f_i = 1/2*f_{i-1}+1/2*f_{i+1}$$

上式为等差数列递推式
设$f_1=x$；则$f_2=2*x$，$f_3=3*x$，...，$f_{sum}=sum*x$


### Code

我的

```c++
/* helpers PAC(3WA)
author: xzqiaochu */
#include <cstdio>

typedef long long ll;

const int MAXN = 1e7 + 7, P = 998244353;

int n, s, a[MAXN];
ll sp;

int zpow(int a, int b, int p)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ll)ans * a % p;
        a = (ll)a * a % p;
        b >>= 1;
    }
    return ans;
}

int main()
{
    // freopen("helpers.in", "r", stdin);
    // freopen("helpers.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i), s += a[i];
    sp = zpow(s, P - 2, P);
    for (int i = 1; i <= n; i++)
        printf("%lld ", a[i] * sp % P);
    return 0;
}
```

标程

```c++
/* helpers PAC(3WA)
author: std */
#include <bits/stdc++.h>

#define LL long long

const int MAXB = 1e8 + 10;
char ibuf[MAXB], *icp = ibuf;

void rd(int &x)
{
	x = 0;
	while (*icp < '0' || '9' < *icp)
		icp++;
	while ('0' <= *icp && *icp <= '9')
		x = x * 10 + *icp++ - 48;
}

char obuf[MAXB], *ocp = obuf;

void write(int x)
{
	static char s[10];
	static int top = 0;
	for (; x; x /= 10)
		s[top++] = x % 10 + 48;
	while (top)
		*ocp++ = s[--top];
	*ocp++ = ' ';
}

const int mod = 998244353;
const int MAXN = 10000010;

inline int mul(const int a, const int b) { return (LL)a * b % mod; }

inline int qpow(int a, int x)
{
	int res = 1;
	for (; x; x >>= 1, a = mul(a, a))
		if (x & 1)
			res = mul(res, a);
	return res;
}

int n, sum, inv;
int a[MAXN];

int main()
{
	// freopen("helpers.in", "r", stdin);
	// freopen("helpers.out", "w", stdout);
	ibuf[fread(ibuf, 1, MAXB, stdin)] = '\0';
	rd(n);
	sum = 0;
	for (int i = 0; i < n; i++)
	{
		rd(a[i]);
		sum += a[i];
	}
	inv = qpow(sum, mod - 2);
	for (int i = 0; i < n; i++)
		write(mul(a[i], inv));
	fwrite(obuf, 1, ocp - obuf, stdout);
	return 0;
}
```
