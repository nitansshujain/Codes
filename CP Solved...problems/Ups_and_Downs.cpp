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
        int n;
        cin >> n;

        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        // O(nlogn) approach
        // vector<int> res(n);
        // sort(v.begin(), v.end());
        // int v_i = 0;
        // for (int i = 0; i < n; i += 2)
        // {
        //     res[i] = v[v_i++];
        // }

        // for (int i = 1; i < n; i += 2)
        // {
        //     res[i] = v[v_i++];
        // }

        // for (auto &x : res)
        //     cout << x << " ";
        // cout << endl;

        // O(n) approach
        for (int i = 0; i < n - 1; i++)
        {
            if (i % 2 == 0)
            {
                if (v[i] > v[i + 1])
                    swap(v[i], v[i + 1]);
            }
            else
            {
                if (v[i] < v[i + 1])
                    swap(v[i], v[i + 1]);
            }
        }

        // for (auto &x : v)
        //     cout << x << " ";
        for (int i = 0; i < n; i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    return 0;
}