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

        vector<int> v(n + 1);
        unordered_map<int, int> mp;
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
            mp[v[i]]++;
        }

        int res_cnt = 0;
        res_cnt = mp[0] * (mp[0] - 1) / 2 + mp[2] * (mp[2] - 1) / 2;
        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = i + 1; j <= n; j++)
        //     {
        //         if (v[i] + v[j] == v[i] * v[j])
        //             res_cnt++;
        //     }
        // }
        cout << res_cnt << endl;
    }
    return 0;
}
