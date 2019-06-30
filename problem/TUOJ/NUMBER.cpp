#include <cstdio>
#include <cmath>

int n;

int main()
{
    scanf("%d", &n);
    if (n <= 10)
    {
        printf("%d", -1);
        return 0;
    }
    for (int i = 10; i <= n; i++)
    {
        bool flag = true;
        int now = i, j = 5, last = 0;
        while (j >= 0)
        {
            int pos = now / pow(10, j);
            if (pos < last)
            {
                flag = false;
                break;
            }
            now -= pos * pow(10, j);
            last = pos;
            j--;
        }
        if (flag)
        {
            printf("%d", i);
            puts("");
        }
    }
    return 0;
}