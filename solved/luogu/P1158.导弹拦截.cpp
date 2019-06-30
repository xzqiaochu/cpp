#include <bits/stdc++.h>

using namespace std;

struct dis
{
    int d1, d2;
}d[100005];

bool cmp(dis a, dis b) {
	return a.d1 < b.d1;
}

int main()
{   
    int x1, y1, x2, y2, n;
    cin >> x1 >> y1 >> x2 >> y2 >> n;
    for(int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        d[i].d1 = (x - x1) * (x - x1) + (y - y1) * (y - y1);
        d[i].d2 = (x - x2) * (x - x2) + (y - y2) * (y - y2);
    }
    sort(d + 1, d + n + 1, cmp); 
    int r2 = 0;
    int ans = d[n].d1;
    for(int i = n - 1; i >= 1; i--) {
        if(r2 < d[i + 1].d2) r2 = d[i + 1].d2;
        ans = min(ans, d[i].d1 + r2);
    }
    cout << ans;
    return 0;
}
