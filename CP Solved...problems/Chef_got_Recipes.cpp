#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int main()
{
    fast;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        // vector<string> s(n);
        vector<ll> dp(32);
        for (ll i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            ll temp = 0;
            for (ll i = 0; i < s.size(); i++)
            {
                if (s[i] == 'a')
                    temp = temp | (1 << 0);
                else if (s[i] == 'e')
                    temp = temp | (1 << 1);
                else if (s[i] == 'i')
                    temp = temp | (1 << 2);
                else if (s[i] == 'o')
                    temp = temp | (1 << 3);
                else
                    temp = temp | (1 << 4);
            }
            dp[temp]++;
        }

        ll ans = 0;
        for (ll i = 0; i < 32; i++)
        {
            for (ll j = i + 1; j < 32; j++)
            {
                if ((i | j) == 31)
                    ans += (dp[i] * dp[j]);
            }
        }
        ans += (dp[31] * (dp[31] - 1) / 2);
        cout << ans << "\n";
        // int res_cnt = 0;
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = i + 1; j < n; j++)
        //     {
        //         string temp = s[i] + s[j];

        //         unordered_set<char> seta(temp.begin(), temp.end());
        //         if (seta.size() == 5)
        //             res_cnt++;
        //     }
        // }
        // cout << res_cnt << endl;
    }
    return 0;
}

// 1
// 3
// aaooaoaooa
// uiieieiieieuuu
// aeioooeeiiaiei
// 3