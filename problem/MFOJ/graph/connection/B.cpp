//珍珠 AC
#include <cstdio>

const int MAXN = 105;

bool gra[MAXN][MAXN];
int h[MAXN], l[MAXN];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int from, to;
        scanf("%d%d", &from, &to);
        gra[from][to] = true;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            if (k != i)
                for (int j = 1; j <= n; j++)
                    if (k != j && i != j && gra[i][k] && gra[k][j])
                        gra[i][j] = true;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (gra[i][j])
                h[j]++, l[i]++;
    int mid = (n + 1) >> 1, cnt = 0;
    for (int i = 1; i <= n; i++)
        if (h[i] >= mid || l[i] >= mid)
            cnt++;
    printf("%d", cnt);
    return 0;
}