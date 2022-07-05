#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int primes[10000001];
// vector<int> primes(1000000000); // max_size exceeded
void sieve(int n)
{
    for (int i = 0; i <= n; i++)
        primes[i] = 1;
    primes[0] = primes[1] = 0;

    for (int i = 2; i * i <= n; i++)
    {
        if (primes[i] == 1)
        {
            for (int j = i * i; j <= n; j += i)
            {
                primes[j] = 0;
            }
        }
    }
}
int main()
{
    fast;
    int t;
    cin >> t;

    while (t--)
    {
        int a, b;
        cin >> a >> b;
        sieve(b);

        for (int i = a; i <= b; i++)
        {
            if (primes[i] == 1)
                cout << i << "\n";
        }
        cout << "\n";
    }

    return 0;
}