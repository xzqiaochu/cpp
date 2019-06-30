#include <cstdio>
#include <cmath>

bool pos[31];
char mode;
int n, m, p;

void setpos(int p)
{
    int i = 0;
    while (p)
    {
        pos[i] = p % 2;
        p /= 2;
        i++;
    }
}

int rtoz(int now)
{
    if (now == 1)
    {
        return 2 * pos[1] + pos[0];
    }
    return pow(2, n) * pos[now] + pow(2, n - 1) * pos[n - 1] + rtoz(now - 2);
}

int main()
{
    scanf("%d%d", &n, &m);
    while (m)
    {
        scanf("%c%d", &mode, &p);
        setpos(p);
        // for (int i = 0; i <= 5; i++)
        //     printf("%d ", pos[i]);
        printf("%d", rtoz(n * 2));
        m--;
    }
    return 0;
}