#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int main()
{
    fast;
    int n;
    cin >> n;

    // vector<pair<int, int>> v;
    int lead;
    pair<int, int> res; //player,max_lead

    int sum_a = 0, sum_b = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        sum_a += a;
        sum_b += b;
        if (sum_a > sum_b)
        {
            lead = sum_a - sum_b;
            if (lead > res.second)
            {
                res = {1, lead};
                // res.first = 1;
                // res.second = lead;
            }
        }
        else
        {
            lead = sum_b - sum_a;
            if (lead > res.second)
            {
                res = {2, lead};
                // res.first = 2;
                // res.second = lead;
            }
        }
    }

    cout << res.first << " " << res.second << endl;

    return 0;
}