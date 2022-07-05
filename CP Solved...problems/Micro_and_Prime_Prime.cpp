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

bool isprime[1000002];
int pp[1000002];
void sieve()
{
    isprime[0] = isprime[1] = true;

    for (lli i = 2; i * i <= 1000002; i++)
    {
        if (!isprime[i])
        {
            for (lli j = i * i; j <= 1000002; j += i)
            {
                isprime[j] = true;
            }
        }
    }

    lli cnt = 0;
    for (lli i = 1; i <= 1000002; i++)
    {
        if (isprime[i] == false)
        {
            cnt++;
        }

        if (isprime[cnt] == false)
        {
            pp[i] = 1;
        }
    }

    for (int i = 1; i <= 1000002; i++)
    {
        pp[i] += pp[i - 1];
    }
}
int main()
{
    nitro;
    sieve();
    lli t = 1;
    cin >> t;

    while (t-- > 0)
    {
        lli l, r;
        cin >> l >> r;
        lli res = pp[r] - pp[l - 1];

        // for (; l <= r; l++)
        // {
        //     res += (pp[l]);
        // }

        cout << res << endl;
    }
}