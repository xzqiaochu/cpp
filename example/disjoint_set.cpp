/* 并查集
出处：MFOJ queue D
最后修改时间：2019-05-01 */

/* 家庭问题(family)
Description
    有n个人，编号为1,2,……n，另外还知道存在K个关系。一个关系的表达为二元组（α，β）形式，表示α，β为同一家庭的成员。
    当n，k和k个关系给出之后，求出其中共有多少个家庭、最大的家庭中有多少人？
    例如：n＝6，k＝3，三个关系为（1,2），(1,3)，(4,5)
    此时，6个人组成三个家庭，即：｛1,2,3｝为一个家庭，｛4,5｝为一个家庭，｛6｝单独为一个家庭，第一个家庭的人数为最多。
Input
    文件的第一行为n,k二个整数（1≤n≤100）（用空格分隔）
    接下来的k行，每行二个整数（用空格分隔）表示关系
Output
    二个整数（分别表示家庭个数和最大家庭人数）
输入样例 1 
6 3
1 2
1 3
4 5
输出样例 1
3 3 */

#include <cstdio>
#include <algorithm>

using namespace std;

int n, k, cnt, maxn, fa[101], sz[101]; //fa为父节点，sz为成员个数（当且仅当此节点为代表元素）

int getroot(int n) //获取根（代表元素）
{
	if (fa[n] == n) //如果是根节点
		return n;
	return fa[n] = getroot(fa[n]); //父亲的父亲 就是 父亲
}

void merge(int u, int v) //合并
{
	int rtu = getroot(u), rtv = getroot(v);
	if (rtu == rtv) //如果已经是一家的了
		return;
	if (rtu > rtv) //成员少的 加入 成员多的
		fa[rtv] = rtu, sz[rtu] += sz[rtv]; //更改父节点，合并人数
	else
		fa[rtu] = rtv, sz[rtv] += sz[rtu];
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		fa[i] = i, sz[i] = 1;
	for (int i = 1, u, v; i <= k; i++)
	{
		scanf("%d%d", &u, &v);
		merge(u, v);
	}
	for (int i = 1; i <= n; i++)
		if (fa[i] == i)
		{
			cnt++;
			maxn = max(maxn, sz[i]);
		}
	printf("%d %d", cnt, maxn);
	return 0;
}