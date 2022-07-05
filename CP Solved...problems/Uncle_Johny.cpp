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
        int n;
        cin >> n;

        vector<int> v;
        for (int i = 1; i <= n; i++)
        {
            int temp;
            cin >> temp;
            v.push_back(temp);
        }
        int song_index;
        cin >> song_index;

        int song_value = v[song_index - 1];

        sort(v.begin(), v.end());

        auto itr = find(v.begin(), v.end(), song_value);

        if (itr != v.end())
        {
            cout << itr - v.begin() + 1 << endl;
        }
    }

    return 0;
}