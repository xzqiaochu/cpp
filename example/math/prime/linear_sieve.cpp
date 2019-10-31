/* 线性筛法
时间复杂度：O(N)
出处：算法竞赛-数学知识-质数 0x31 P134-135
最后修改时间：2019-02-05 */
#include <iostream>
#include <cstring>

#define MAX_N 1000001

using namespace std;

int m, v[MAX_N], primes[MAX_N];

void sieve(int n)
{
    memset(v, 0, sizeof(v)); //最小质因子
    m = 0; //质数数量
    for (int i = 2; i <= n; i++)
    {
        if (v[i] == 0) //i是素数
        {
            v[i] = i;
            primes[++m] = i;
        }
        //给当前的数i乘上一个质因子p（p <= v[i]）
        for (int j = 1; j <= m; j++)
        {
            if (primes[j] > v[i] || i * primes[j] > n) break; //p > v[i]，或超出范围，停止循环
            v[i * primes[j]] = primes[j]; //primes[j]是合数 i * primes[j] 的最小质因子
        }
    }
}


int main ()
{
    int n;
    cin >> n;
    sieve(n);
    for (int i = 1; i <= m; i++)
        cout << primes[i] << ' ';
    return 0;
}