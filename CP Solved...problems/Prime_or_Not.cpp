#include <bits/stdc++.h>
using namespace std;

#define nitro ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int>
#define lli long long int
#define vlli vector<long long int>
#define loop0(i, n) for (int i = 0; i < n; i++)
#define loop1(i, n) for (int i = 1; i <= n; i++)
#define endl '\n'
#define vpi vector<pair<int, int>>
#define vplli vector<pair<long long int, long long int>>
#define mod 1000000007

// bool isPrime(lli n)
// {
//     if (n == 1)
//         return false;

//     for (int i = 2; i * i <= n; i++)
//     {
//         if (n % i == 0)
//             return false;
//     }
//     return true;
// }

bool isPrime[100000001];

void sieve()
{
    lli maxN = 100000001;
    loop1(i, maxN) isPrime[i] = true;
    isPrime[0] = isPrime[1] = false;

    for (lli i = 2; i * i <= maxN; i++)
    {
        if (isPrime[i])
        {
            for (lli j = i * i; j <= maxN; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}
int main()
{
    sieve();
    int t = 1;
    cin >> t;

    while (t-- > 0)
    {
        lli n;
        cin >> n;

        if (isPrime[n])
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}