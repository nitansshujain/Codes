#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int>
#define lli long long int
#define vlli vector<long long int>
#define loop0(i, n) for (int i = 0; i < n; i++)
#define loop1(i, n) for (int i = 1; i <= n; i++)
#define endl '\n'
#define vpi vector<pair<int, int>>
#define vplli vector<pair<long long int, long long int>>
#define mod 1000000007

int main()
{
    lli t = 1;
    cin >> t;
    while (t--)
    {
        lli n;
        cin >> n;
        vector<lli> v(n);
        loop0(i, n)
        {
            cin >> v[i];
        }

        lli res = 0, f = 1;

        for (lli i = 0; i < 60; i++)
        {
            lli cnt0 = 0, cnt1 = 0;
            for (lli j = 0; j < n; j++)
            {
                if (v[j] & (f << i))
                    cnt1++;
                else
                    cnt0++;
            }
            if (cnt0 < cnt1)
            {
                res |= (f << i);
            }
        }
        cout << res << endl;
    }
    return 0;
}