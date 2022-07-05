#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> v(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
        }

        bool partial_pass = true;
        bool full_pass = true;
        for (int i = 1; i <= m; i++)
        {
            if (v[i] != 1)
            {
                partial_pass = false;
                break;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (v[i] != 1)
            {
                full_pass = false;
                break;
            }
        }
        // cout << full_pass << " " << partial_pass << " ";
        if (full_pass)
            cout << 100 << endl;
        else if (partial_pass)
            cout << k << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}