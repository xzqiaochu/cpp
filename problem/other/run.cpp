#include <iostream>
#include <cmath>
#include <map>
#include <queue>

using namespace std;

int n, xs, ys, x1, Y1, x2, y2, dogx[10000], dogy[10000], pro[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}, v[10000][10000];

struct xy
{
    int x, y, mind, s;
};

map <int, int> ans;
queue <xy> q;

bool judge(xy next)
{
    if (next.x >= 0 && next.x < xs && next.y >= 0 && next.y < ys) return true;
    else return false;
}

void bfs()
{
    xy st;
    st.x = x1;
    st.y = Y1;
    st.s = 0;
    st.mind = 0x3f3f3f3f;
    for (int i = 0; i < n; i++)
        st.mind = min(st.mind, abs(x1 - dogx[i]) + abs(Y1 - dogy[i]));
    q.push(st);
    v[0][0] = true;
    while(!q.empty())
    {
        xy now = q.front();
        q.pop();
        if (now.x == x2 && now.y == y2)
        {
            if (ans[now.mind] == 0)
            {
                ans[now.mind] = now.s;
            }
            else
            {
                ans[now.mind] = min(ans[now.mind], now.s);
            }
            continue;
        }
        for (int i = 0; i < 4; i++)
        {
            xy next;
            next.x = now.x + pro[i][0];
            next.y = now.y + pro[i][1];
            if (judge(next))
            {
                int nextd = 0x3f3f3f3f;
                for (int j = 0; j < n; j++)
                    nextd = min(nextd, abs(next.x - dogx[j]) + abs(next.y - dogy[j]));
                next.mind = min(now.mind, nextd);
                if (next.mind > v[next.x][next.y])
                {
                    v[next.x][next.y] = next.mind;
                    next.s = now.s + 1;
                    q.push(next);
                }
            }
        }
    }
}

int main()
{
    cin >> n >> xs >> ys >> x1 >> Y1 >> x2 >> y2;
    for (int i = 0; i < n; i++)
        cin >> dogx[i] >> dogy[i];
    bfs();
    // map <int, int> :: iterator iter;
    // for (iter = ans.begin(); iter != ans.end(); iter++)
        // cout << iter -> first << ' ' << iter -> second << endl;
    cout << (--ans.end()) -> first << ' ' << (--ans.end()) -> second;
    return 0;
}