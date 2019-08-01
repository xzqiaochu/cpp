// A - FatMouse' Trade (https://vjudge.net/contest/316356#problem/A)
// auhtor: xzqiaochu
// status: AC
#include <cstdio>
#include <algorithm>

using std::sort;

const int SZ = 1007;

int n, m;
struct Node
{
	int v, w;
	double per;
} a[SZ];

bool cmp(Node a, Node b)
{
	return a.per > b.per;
}

int main()
{
    
    while (1)
    {
    	scanf("%d%d", &m, &n);
    	if (n == -1)
    		break;
        for (int i = 1; i <= n; i++)
            scanf("%d%d", &a[i].v, &a[i].w), a[i].per = (double)a[i].v / a[i].w;
        sort(a + 1, a + n + 1, cmp);
        double ans = 0, left = m;
        for (int i = 1; i <= n; i++)
        {
        	if (a[i].w <= left)
        		ans += a[i].v, left -= a[i].w;
        	else
        	{
        		ans += a[i].v * left / a[i].w;
        		break;
        	}
        }
        printf("%.3f\n", ans);
    }
    return 0;
}
