#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    if (s.length() == 20) //一个中文字符占两字节
    {
        cout << s.substr(0, 14) << endl;
        cout << s.substr(6) << endl;
        for (int i = 18; i >= 6; i -= 2)
            cout << s.substr(i, 2);
        cout << endl;
        for (int i = 12; i >= 0; i -= 2)
            cout << s.substr(i, 2);
        cout << endl;
    }
}