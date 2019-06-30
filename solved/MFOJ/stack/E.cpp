//车厢调度
#include <cstdio>

int n, a[1001];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    for (int i = 0; i < n; i++)
    {
        int now = a[i], minn = 0x3f3f3f3f;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < now)
            {
                if (a[j] < minn)
                {
                    minn = a[j];
                }
                else
                {
                    printf("NO");
                    return 0;
                }
            }
        }
    }
    printf("YES");
    return 0;
}