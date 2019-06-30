//食物链(eat) AC
#include <cstdio>

const int MAXN = 5e4 + 7;

int n, k, cnt, fa[3 * MAXN]; //3倍

/*
1 - n 同类
n+1 - 2n 食物
2n+1 - 3n 天敌
*/

int get(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = get(fa[x]);
}

void merge(int x, int y)
{
    fa[get(x)] = get(y);
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= 3 * n; i++)
        fa[i] = i;
    for (int i = 1; i <= k; i++)
    {
        int d, x, y;
        scanf("%d%d%d", &d, &x, &y);
        if (x > n || y > n)
        {
            cnt++;
            continue;
        }
        int x_food = x + n, x_en = x + 2 * n;
        int y_food = y + n, y_en = y + 2 * n;
        if (d == 1) //x和y是同类
        {
            if (get(x) == get(y_food) || get(x) == get(y_en))
                cnt++;
            else
            {
                merge(x, y);
                merge(x_food, y_food);
                merge(x_en, y_en);
            }
            
        }
        else // d == 2 x吃y x是y的天敌
        {
            if (get(x) == get(y) || get(x) == get(y_food))
                cnt++;
            else
            {
                merge(x, y_en);
                merge(x_food, y);
                merge(x_en, y_food);
            }
        }
        
    }
    printf("%d", cnt);
    return 0;
}