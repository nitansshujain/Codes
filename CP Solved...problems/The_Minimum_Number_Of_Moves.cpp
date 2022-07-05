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
        vector<int> v; //NO NEED

        int min_elem = INT_MAX;

        int total_sum = 0;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            total_sum += temp;
            min_elem = min(min_elem, temp);
            v.push_back(temp);
        }

        cout << total_sum - min_elem * n << "\n";
    }
    return 0;
}