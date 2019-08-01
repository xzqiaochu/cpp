// prime
// author: xzqiaochu
// status: AC
#include <cstdio>
#include <cmath>
#include <algorithm>

const int MAXN = 1007;

int n, m, a[MAXN], ans, bound;
bool *flag, *flag2;

void init()
{
    std::sort(a + 1, a + m + 1);
    bound = sqrt(n);
    ans = 0;
    for (int i = 1; i <= n; i++)
        flag[i] = false;
}

int try_change(int x)
{
    int cnt = 0;
    for (int i = x; i <= n; i += x)
        if (flag[i] == false)
            cnt++;
        else
            cnt--;
    return cnt;
}

void do_change(int x)
{
    for (int i = x; i <= n; i += x)
        flag[i] = !flag[i];
}

int count()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (flag[i])
            cnt++;
    return cnt;
}

void changeToTemp()
{
    
    for (int i = 1; i <= n; i++)
        flag2[i] = flag[i];
    std::swap(flag, flag2);
}

void changeToMaster()
{
    std::swap(flag, flag2);
}

void calc(int x)
{
    changeToTemp();
    for (int i = 1; i <= m; i++)
    {
        if (a[i] < bound)
            continue;
        int now_change = try_change(a[i]);
        if (now_change > 0)
            do_change(a[i]), x += now_change;
    }
    ans = std::max(ans, x);
    changeToMaster();
}

void dfs(int now)
{
    if (a[now] >= bound || now > m)
    {
        calc(count());
        return;
    }
    // 选
    do_change(a[now]);
    dfs(now + 1);
    do_change(a[now]);
    // 不选
    dfs(now + 1);
}

int main()
{
    // freopen("prime.in", "r", stdin);
    // freopen("prime.out", "w", stdout);
    flag = new bool[MAXN];
    flag2 = new bool[MAXN];
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++)
            scanf("%d", a + i);
        init();
        dfs(1);
        printf("%d\n", ans);
    }
    return 0;
}