// 家谱(gen) AC
#include <iostream>
#include <cstring>
#include <map>

using namespace std;

const int SZ = 5e4 + 7;

map<string, string> fa;

string get(string x)
{
    return fa[x] == x ? x : (fa[x] = get(fa[x]));
}

int main()
{
    ios::sync_with_stdio(false);
    char c;
    string name, father;
    while (cin >> c && c != '$')
    {
        cin >> name;
        if (c == '#')
        {
            if (fa[name] == "")
                fa[name] = name;
            father = name;
        }
        if (c == '+')
            fa[name] = father;
        if (c == '?')
            cout << name << ' ' << get(name) << endl;
    }
    return 0;
}