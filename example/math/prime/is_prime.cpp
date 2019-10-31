/* 试除法判断质数
时间复杂度：O(sqrt(N))
出处：算法竞赛-数学知识-质数 0x31 P133
最后修改时间：2019-02-05 */
#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int n)
{
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return false;
    return true;
}

int main ()
{
    int n;
    cin >> n;
    if (is_prime(n)) cout << "YES";
    else cout << "NO";
    return 0;
}