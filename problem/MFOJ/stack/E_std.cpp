//车厢调度
#include <cstdio>
#include <stack>

using namespace std;

int n, a[1001];
stack<int> p;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    for (int i = 1; i <= n; i++)
    {
        for (int i = 1, flag = 1; i <= n; i++)
        {
            while (flag <= a[i])
                p.push(flag++);
            if (p.top() == a[i])
            {
                p.pop();
            }
            else
            {
                printf("NO");
                return 0;
            }
        }
    }
    printf("YES");
    return 0;
}