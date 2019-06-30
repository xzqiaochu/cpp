/* 试除法判断质数-v2
时间复杂度：O(sqrt(N)) （优化了常数）
出处：算法竞赛-数学知识-质数 0x31 P133
最后修改时间：2019-02-07 */
#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int n)
{
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i <= sqrt(n); i += 2)
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