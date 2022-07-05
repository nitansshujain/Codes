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
        int n;
        cin >> n;

        int k;
        cin >> k;
        int res_cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            int after_add_k = temp + k;
            if (after_add_k % 7 == 0)
                res_cnt++;
        }
        cout << res_cnt << "\n";
    }

    return 0;
}