/* 试除法质因数分解
时间复杂度：O(sqrt(N))
出处：算法竞赛-数学知识-质数 0x31 P135-136
最后修改时间：2019-02-05 */
#include <iostream>
#include <cmath>

#define MAX_N 1000001

using namespace std;

int m, p[MAX_N], c[MAX_N];

void divide(int n)
{
    m = 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0) //i是质数
        {
            p[++m] = i;
            c[m] = 0;
            while (n % i == 0)
            {
                n /= i;
                c[m]++;
            }
        }
    }
    if (n > 1) //n是质数
    {
        p[++m] = n;
        c[m] = 1;
    }
}

int main()
{
    int n;
    cin >> n;
    divide(n);
    for (int i = 1; i <= m; i++)
        cout << p[i] << '^' << c[i] << ' ';
    return 0;
}