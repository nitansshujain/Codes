#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define mod 1000000007
lli dp[10000001];
// lli inv[10000001];
lli mul[10000001];
lli power(lli a, lli n)
{
    lli result = 1;

    while (n)
    {
        if (n & 1)
            result = (result * a) % mod;

        n >>= 1;
        a = (a * a) % mod;
    }

    return result;
}

lli hashF(string patt)
{
    lli value = 0;
    lli p = 31;
    lli p_power = 1;

    for (auto c : patt)
    {
        value = (value + (c - 'a' + 1) * p_power) % mod;
        p_power = (p_power * p) % mod;
    }
    return value;
}

void initialise(string s)
{
    lli p_power = 1;
    lli p = 31;
    // inv[0] = 1;
    dp[0] = (s[0] - 'a' + 1);
    mul[0] = 1;
    for (int i = 1; i < s.size(); i++)
    {
        char c = s[i];
        p_power = (p_power * p) % mod;
        mul[i] = power(p, i);
        // inv[i] = power(p_power, mod - 2);

        dp[i] = (dp[i - 1] + (c - 'a' + 1) * p_power) % mod;
    }
}

lli substr_hash(int l, int r)
{
    int res = dp[r];
    if (l > 0)
    {
        res = (res - dp[l - 1] + mod) % mod;
    }
    // res = (res * inv[l]) % mod;

    return res;
}

int main()
{
    int n;
    string patt, s;

    while (cin >> n)
    {
        cin >> patt;
        cin >> s;

        lli patt_int = hashF(patt);

        initialise(s);

        for (int l = 0, r = patt.size() - 1; r < s.size(); l++, r++)
        {
            if (patt_int * mul[l] == substr_hash(l, r))
            {
                cout << l << endl;
            }
        }
        cout << endl;
    }
    return 0;
}
