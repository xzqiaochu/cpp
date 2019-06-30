#include <cstdio>
#include <cmath>

#define MAX_N 1000001

bool no_prime[MAX_N];
int primes[MAX_N], s[MAX_N];

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

void digit()
{
    for (int i = 1; i <= MAX_N - 1; i++)
    {
        if (no_prime[i] == true)
        {
            s[i] = s[i - 1];
            continue;
        }
        int now = i, sum = 0;
        for (int j = 7; j >= 0; j--)
        {
            int cnt = now / pow(10, j);
            sum += cnt;
            now -= cnt * pow(10, j);
        }
        if (no_prime[sum] == false)
            s[i] = s[i - 1] + 1;
        else
            s[i] = s[i - 1];
    }
}

int main()
{
    sieve(MAX_N - 1);
    digit();
    int t;
    scanf("%d", &t);
    while (t)
    {
        t--;
        int a, b;
        scanf("%d %d", &a, &b);
        int ans = s[b] - s[a - 1];
        printf("%d\n", ans); 
    }
    return 0;
}