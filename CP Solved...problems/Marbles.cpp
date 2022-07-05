#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define lli long long int
#define vlli vector<long long int>
#define loop0(i, n) for (int i = 0; i < n; i++)
#define loop1(i, n) for (int i = 1; i <= n; i++)
#define endl '\n'
#define vpi vector<pair<int, int>>
#define vplli vector<pair<long long int, long long int>>
#define mod 1000000007

// binomial coefficient in linear time
lli C(lli n, lli r)
{
    lli ans = 1;
    if (r > n - r)
    {
        r = n - r;
    }

    for (lli i = 1; i <= r; i++)
    {
        ans *= (n - i + 1);
        ans /= i;
    }
    return ans;
}
// end of binomial coefficient

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        lli n, r;
        cin >> n >> r;

        cout << C(n - 1, r - 1) << endl;
    }
}