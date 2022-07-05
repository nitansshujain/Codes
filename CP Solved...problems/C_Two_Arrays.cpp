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

lli fact(lli n)
{
    if (n == 1)
        return 1;
    return n * fact(n - 1);
}
lli C(lli n, lli r)
{
    return fact(n) / (fact(r) * fact(n - r));
}

// lli C(lli n, lli r)
// {
//     lli ans = 1;
//     if (r > n - r)
//     {
//         r = n - r;
//     }

//     for (lli i = 1; i <= r; i++)
//     {
//         ans *= (n - i + 1);
//         ans /= i;
//     }
//     return ans;
// }

int main()
{
    lli n, m;
    cin >> n >> m;
    //r->n and n->2m in (2m+n-1)C(n-1)
    lli res = C(2 * m + n - 1, 2 * m);
    cout << res % mod << endl;
}