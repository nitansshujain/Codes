#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int>
#define lli long long int
#define vlli vector<long long int>
#define loop0(i, n) for (int i = 0; i < n; i++)
#define loop1(i, n) for (int i = 1; i <= n; i++)
#define endl '\n'
#define vpi vector<pair<int, int>>
#define vplli vector<pair<long long int, long long int>>
#define mod 1000000007

bool isPrime[90000001];
vi res;

void sieve()
{
    int maxN = 90000001;
    isPrime[0] = isPrime[1] = true;

    for (int i = 2; i * i <= maxN; i++)
    {
        if (!isPrime[i])
        {
            for (int j = i * i; j <= maxN; j += i)
            {
                isPrime[j] = true;
            }
        }
    }

    for (int i = 2; i <= maxN; i++)
    {
        if (!isPrime[i])
        {
            res.push_back(i);
        }
    }
}
int main()
{
    sieve();
    int t = 1;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        cout << res[n - 1] << endl;
    }
}