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
        int n, m;
        cin >> n >> m;

        vector<int> v(n + 1);
        v[0] = 1;

        for (int i = 1; i <= m; i++)
        {
            int temp;
            cin >> temp;
            v[temp] = 1;
        }

        vector<int> cook;
        vector<int> saathi;

        bool cook_turn = 1;
        for (int i = 1; i <= n; i++)
        {
            if (v[i] == 0)
            {
                if (cook_turn == 1)
                {
                    cook.push_back(i);
                }
                else
                {
                    saathi.push_back(i);
                }
                cook_turn ^= 1;
            }
        }

        for (auto c : cook)
        {
            cout << c << " ";
        }
        cout << "\n";

        for (auto s : saathi)
        {
            cout << s << " ";
        }
        cout << "\n";
    }
    return 0;
}