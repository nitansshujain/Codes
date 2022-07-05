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
        int x, y, k, n;
        cin >> x >> y >> k >> n;
        int pages_left = x - y;

        bool is_possible = 0;

        vector<int> pages(n);
        vector<int> cost(n);
        for (int i = 0; i < n; i++)
        {
            int p, c;
            cin >> p >> c;

            pages[i] = p;
            cost[i] = c;
            // if (c <= k and pages_left <= p)
            // {
            //     is_possible = true;
            //     break;
            // }
        }

        for (int i = 0; i < n; i++)
        {
            if (cost[i] <= k and pages_left <= pages[i])
            {
                is_possible = true;
                break;
            }
        }

        if (is_possible)
        {
            cout << "LuckyChef"
                 << "\n";
        }
        else
        {
            cout << "UnluckyChef"
                 << "\n";
        }
    }
    return 0;
}