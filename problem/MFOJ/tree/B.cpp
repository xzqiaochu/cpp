//单词查找树
#include <iostream>
#include <string>
#include <set>

using namespace std;

int cnt = 1;
string s, last;
set<string> a;
set<string>::iterator it;

int ssubs(string s1, string s2)
{
    int len = s1.length();
    for (int i = 0; i < len; i++)
        if (s1[i] != s2[i])
            return s1.length() - i;
    return 0;
}

int main()
{
    while (cin >> s)
        a.insert(s);
    last = *a.begin();
    cnt += last.size();
    for (it = a.begin()++; it != a.end(); it++)
    {
        cnt += ssubs(*it, last);
        last = *it;
    }
    printf("%d", cnt);
    return 0;
}