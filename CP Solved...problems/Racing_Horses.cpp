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

        sort(v.begin(), v.end());

        int min_ = v[1] - v[0];

        for (int i = 2; i < n; i++)
        {
            if (v[i] - v[i - 1] < min_)
            {
                min_ = v[i] - v[i - 1];
            }
        }
        cout << min_ << endl;
    }

    return 0;
}