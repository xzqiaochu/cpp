#include <iostream>

using namespace std;

#define MAX_N 1000001

using namespace std;

bool no_prime[MAX_N];
int primes[MAX_N];

void sieve(int n)
{
    no_prime[0] = no_prime[1] = true;
    for (int i = 2; i <= n; i++)
    {
        if (no_prime[i] == false)
            primes[++primes[0]] = i;
        for (int j = 1; j <= primes[0]; j++)
        {
            if (i * primes[j] > n)
                break;
            no_prime[i * primes[j]] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    sieve(n);
    for (int i = 1; i <= primes[0]; i++)
        cout << primes[i] << ' ';
    return 0;
}