#include <iostream>

using namespace std;

int n, tar_v, ans = 0x3f3f3f3f, v[101], w[101];

void dfs(int now, int sv, int sw)
{
    if (sv >= tar_v)
    {
        ans = min(ans, sw);
    }
    if (now <= n)
    {
        dfs(now + 1, sv, sw);
        dfs(now + 1, sv + v[now], sw + w[now]);
    }
}

int main()
{
    cin >> n >> tar_v;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];
    dfs(1, 0, 0);
    cout << ans;
}