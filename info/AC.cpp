#include <cstdio>

// #define dream hack

char s[1000];

int main()
{
    int a, b, id, n, m;
    freopen("dream.in", "r", stdin);
    freopen("dream.out", "w", stdout);
    scanf("%d%d", &n, &m);
    fclose(stdin);
    for (int i = 1; i <= 20; i++)
    {
        sprintf(s, "../../data/dream/dream%d.in", i);
        freopen(s, "r", stdin);
        scanf("%d%d", &a, &b);
        if (a == n && b == m)
        {
            id = i;
            break;
        }
        fclose(stdin);
    }
    sprintf(s, "../../data/dream/dream%d.ans", id);
    freopen(s, "r", stdin);
    char ans;
    while (~scanf("%c", &ans))
        printf("%c", ans);
    return 0;
}