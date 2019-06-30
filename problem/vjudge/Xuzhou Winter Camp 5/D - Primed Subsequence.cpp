#include <cstdio>

#define MAX_N 10011

bool no_prime[MAX_N];
int primes[MAX_N], a[MAX_N], s[MAX_N];

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

bool is_prime(int n)
{
    if (n <= 10010)
    {
        if (no_prime[n] == true)
            return false;
        else
            return true;
    }
    else
    {
        for (int i = 1; i <= primes[0]; i++)
        {
            if (primes[i] > n)
                break;
            if (n % primes[i] == 0)
                return false;
        }
        return true;
    }
}

int main()
{
    sieve(10010);
    int t;
    scanf("%d", &t);
LOOP:
    while (t)
    {
        t--;
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", a + i);
            s[i] = s[i - 1] + a[i];
        }
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= n - i + 1; j++)
            {
                int sum = s[j + i - 1] - s[j - 1];
                if (is_prime(sum) == true)
                {
                    printf("Shortest primed subsequence is length %d:", i);
                    for (int k = j; k <= j + i - 1; k++)
                        printf(" %d", a[k]);
                    puts("");
                    goto LOOP;
                }
            }
        }
        printf("This sequence is anti-primed.\n");
    }
    return 0;
}