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
        for (int i = 1; i <= n; i++)
            cin >> v[i];

        int mx = *max_element(v.begin(), v.end());

        int subarray_size = 0;
        vector<int> subarray_sizes;
        for (int i = 1; i <= n; i++)
        {
            if (v[i] != mx)
                subarray_size++;
            else
            {
                subarray_sizes.push_back(subarray_size);
                subarray_size = 0;
            }
        }
        if (subarray_size != 0)
        {
            subarray_sizes[0] += subarray_size;
        }

        int res = 0;
        for (int i = 0; i < subarray_sizes.size(); i++)
        {
            res += max(subarray_sizes[i] - n / 2 + 1, 0);
        }
        cout << res << endl;
        // vector<int> temp;
        // for (int i = n; i >= 1; i--)
        // {
        //     if (v[i] == mx)
        //         temp.push_back(i);
        // }
        // int n_temp = temp.size();
        // if (temp.size() == n)
        //     cout << 1 << " " << n << endl;
        // else if ((temp[0] - temp[n_temp - 1]) >= (n / 2))
        //     cout << 2 << " " << 0 << endl;

        // else if (n_temp > (n / 2))
        //     cout << 3 << " " << 0 << endl;

        // else if (n_temp == 1)
        //     if (temp[0] > (n / 2))
        //         cout << 4 << " " << n - temp[0] + 1 << endl;
        //     else
        //         cout << 5 << " " << n - temp[0] << endl;
        // else
        // {
        //     cout << 6 << " " << n - temp[n_temp - 1] - temp[0] << endl;
        // }
    }
    return 0;
}
