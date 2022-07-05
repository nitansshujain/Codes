#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long e, k;
        cin >> e >> k;

        long long cnt = 1;

        while (true)
        {
            e = e / k;
            if (e >= 1)
            {
                cnt++;
            }
            else
            {
                break;
            }
        }

        cout << cnt << endl;
    }

    return 0;
}