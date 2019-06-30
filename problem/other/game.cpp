#include <iostream>

using namespace std;

int n, k, ans, a[100001];

void dfs(int now, int flag, int s)
{
    if (now > n)
    {
        ans = max(ans, s);
        return;
    }
    if (now <= n)
    {
        if (flag < k)
        {
            dfs(now + 1, flag + 1, s + a[now]);
            dfs(now + 1, 0, s);
        }
        else
        {
            dfs(now + 1, 0, s);
        }
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dfs(1, 0, 0);
    cout << ans;
    return 0;
}