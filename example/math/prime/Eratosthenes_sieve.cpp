/* Eratosthenes筛法
时间复杂度：O(N log log N) 接近线性
出处：算法竞赛-数学知识-质数 0x31 P134
最后修改时间：2019-02-23 */
#include <iostream>
#include <cstring>

#define MAX_N 1000001

using namespace std;

bool v[MAX_N];
int m, primes[MAX_N];

void sieve(int n)
{
    memset(v, false, sizeof(v)); //合数标记
    m = 0; //质数数量
    for (int i = 2; i <= n; i++)
    {
        if (v[i]) continue; //i是合数
        primes[++m] = i; //i是质数
        for (int j = i * i; j <= n; j += i)
            v[j] = true; //把 i ^ 2, (i + 1) * i, ..., (int)(n / i) * i 标记为合数
    }
}

int main()
{
    int n;
    cin >> n;
    sieve(n);
    for (int i = 1; i <= m; i++)
        cout << primes[i] << ' ';
    return 0;
}