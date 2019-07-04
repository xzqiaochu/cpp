// lemon
#include <cstdio>
#include <cstring>

const int MAXN = 1000;

bool v[MAXN];

bool judge(int m)
{
    memset(v, 0, sizeof(v));
    int s = 1, cnt = 0;
     for (int i = 1; i <= 1000; i++)
    {
        if (v[s] == false)
            v[s] = true, cnt++;
        if (cnt == m)
        {
            printf("%d ", i);
            return true;
        }
        s += i;
        s %= m;
        if (s == 0)
            s = m;
    }
    return false;
}

int main()
{
    for (int i = 1; i <= 1000; i++)
        if (judge(i))
            printf("%d\n", i);
    return 0;
}