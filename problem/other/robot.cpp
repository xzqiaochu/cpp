#include <iostream>
#include <cstring>

using namespace std;

int n, x, y, t;
string s;

int main()
{
    cin >> s >> t;
    unsigned int i = 0;
    int cnt = 1;
    while (1)
    {
        switch (s[i])
        {
            case 'E' :
                x++;
                break;
            case 'W' :
                x--;
                break;
            case 'N' :
                y++;
                break ;
            case 'S' :
                y--;
                break;
        }
        if (i == s.length() - 1)
            i = 0;
        else
            i++;
        if (cnt >= t)
            break;
        else
            cnt++;
    }
    cout << x << ' ' << y;
    return 0;
}