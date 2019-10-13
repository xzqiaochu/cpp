#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    vector <int> *b = new vector <int>; // new申请一个对象
    int m;
    scanf("%d", &m);
    (*b).push_back(m); // b -> push_back(m);
    printf("%d", (*b).back());
    return 0;
}