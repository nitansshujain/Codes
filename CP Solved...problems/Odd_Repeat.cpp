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
        int n, k, s;
        cin >> n >> k >> s;

        int rem_s = s - (n * n);
        int res = (rem_s / (k - 1));
        cout << res << endl;
    }

    return 0;
}