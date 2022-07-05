#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

long long int NcR(int n, int r)
{

    // // p holds the value of n*(n-1)*(n-2)...,
    // // k holds the value of r*(r-1)...
    // long long int p = 1, k = 1;

    // // C(n, r) == C(n, n-r),
    // // choosing the smaller value
    // if (n - r < r)
    //     r = n - r;

    // if (r != 0)
    // {
    //     while (r)
    //     {
    //         p *= n;
    //         k *= r;

    //         // gcd of p, k
    //         long long m = __gcd(p, k);

    //         // dividing by gcd, to simplify
    //         // product division by their gcd
    //         // saves from the overflow
    //         p /= m;
    //         k /= m;

    //         n--;
    //         r--;
    //     }

    //     // k should be simplified to 1
    //     // as C(n, r) is a natural number
    //     // (denominator should be 1 ) .
    // }

    // else
    //     p = 1;

    // // if our approach is correct p = ans and k =1
    // return p;

    long long int ans = 1;
    if (n - r < r)
        r = n - r;

    for (int i = 1; i <= r; i++)
    {
        ans *= (n - i + 1);
        ans /= i;
    }
    return ans;
}

int main()
{
    fast;
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int count_1 = 0;
        for (char c : s)
        {
            if (c == '1')
                count_1++;
        }

        if (count_1 == 0)
        {
            cout << 0 << "\n";
        }
        else if (count_1 == 1)
        {
            cout << 1 << "\n";
        }
        else if (count_1 == 2)
        {
            cout << 3 << "\n";
        }
        else
        {
            long long int ncr = NcR(count_1, 2);
            cout << ncr + count_1 << "\n";
        }
    }
    return 0;
}