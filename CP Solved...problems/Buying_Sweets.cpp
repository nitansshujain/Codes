#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int main()
{
    fast;
    int t;
    cin >> t;

    while (t--)
    {
        int n, x;
        cin >> n >> x;

        float sum_notes = 0;
        // vector<int> v;

        int min_in_notes = INT_MAX;
        for (int i = 1; i <= n; i++)
        {
            int temp;
            cin >> temp;
            sum_notes += temp;
            min_in_notes = min(min_in_notes, temp);
            // v.push_back(temp);
        }

        //Approach 1
        // if (int(sum_notes / x) == int((sum_notes - min_in_notes) / x))
        // {
        //     // cout << sum_notes / x;
        //     cout << -1 << endl;
        // }
        // else
        // {
        //     // sort(v.begin(), v.end());
        //     cout << int(sum_notes / x) << endl;
        // }

        //Approach 2
        int rem = int(sum_notes) % x;
        if (rem >= min_in_notes)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << int(sum_notes / x) << endl;
        }
    }
    return 0;
}