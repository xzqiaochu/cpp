// lemon AC
#include <cstdio>
#include <cmath>

int x;

bool judge()
{
    double temp = log2(x);
    if (temp == (int)temp)
        return true;
    else
        return false;
}

int main()
{
    freopen("lemon.in", "r", stdin);
    freopen("lemon.out", "w", stdout);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &x);
        if (judge())
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}