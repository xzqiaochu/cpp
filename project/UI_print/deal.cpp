#include <cstdio>
#include <map>

using std::map;

map<int, int> data;
map<int, int> num;
map<int, int>::iterator iter;

int main()
{
    freopen("data.txt", "r", stdin);
    freopen("deal.txt", "w", stdout);
    int data_u, data_i;
    while (~scanf("%d%d", &data_u, &data_i))
        data[data_u] += data_i, num[data_u]++;
    for (iter = data.begin(); iter != data.end(); iter++)
    {
        data[iter->first] = (double)data[iter->first] / num[iter->first] + 0.5;
        printf("%d %d\n", iter->first, iter->second);
    }
    return 0;
}