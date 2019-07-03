#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAXN = 70;

int n, cnt, tot, maxn, minn = MAXN, tm[MAXN];

void dfs(int res, int sum, int target, int p)
{
    if (res == 0)
    {
        printf("%d", target);
        exit(0);
    }
    if (sum == target)
    {
        dfs(res - 1, 0, target, maxn);
        return;
    }
    for (int i = p; i >= minn; i--)
    {
        if (tm[i] && i + sum <= target)
        {
            tm[i]--;
            dfs(res, sum + i, target, i);
            tm[i]++;
            if (sum == 0 || sum + i == target)
                break;
        }
    }
    return;
}

int main()
{
    scanf("%d", &n);
    while (n--)
    {
        int temp;
        scanf("%d", &temp);
        if (temp <= 50)
        {
            cnt++;
            tm[temp]++;
            tot += temp;
            maxn = max(maxn, temp);
            minn = min(minn, temp);
        }
    }
    for (int i = maxn; i <= tot >> 1; i++)
        if (tot % i == 0)
            dfs(tot / i, 0, i, maxn);
    printf("%d", tot);
    return 0;
}