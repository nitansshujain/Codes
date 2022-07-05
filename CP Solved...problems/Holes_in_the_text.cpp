#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

int main()
{
    fast;
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        vector<int> v{1, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};
        int res = 0;
        for (char c : s)
        {
            res += v[c - 'A'];
        }

        cout << res << "\n";
    }
    return 0;
}