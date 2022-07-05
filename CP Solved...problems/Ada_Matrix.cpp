#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int>
#define vll vector<long long int>
#define loop0(i, n) for (int i = 0; i < n; i++)
#define loop1(i, n) for (int i = 1; i <= n; i++)
#define loop(i, a, b, n) for (int i = a; i <= b; i++)
#define endl '\n'
#define vpi vector<pair<int, int>>
#define vpll vector<pair<long long int, long long int>>
#define pb push_back
// const int V = 1e5 + 10;
// vector<pair<int, int>> adj[V];
// const int inf = 1e9 + 7;
// vector<int> level(V, inf);
int main()
{
    fast;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        /*
            We need to check the first row only in reverse order, if false-> xor the previous elems 
            Diagonal elems will always be true.
        */

        vector<vector<ll>> mat(n, vector<ll>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> mat[i][j];
            }
        }
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         cout << mat[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        vector<int> check(n);

        for (int i = 0; i < n; i++)
        {
            if (mat[0][i] == i + 1)
                check[i] = true;
        }

        ll res_cnt = 0;
        for (int i = n - 1; i > 0; i--)
        {
            if (check[i] == true)
            {
                // cout << mat[0][i] << "1 ";
                continue;
            }
            else
            {
                // cout << mat[0][i] << "2 ";
                res_cnt++;
                for (int j = i; j > 0; j--)
                {
                    check[j] ^= 1;
                }
            }
        }
        cout << res_cnt << endl;
    }
    return 0;
}