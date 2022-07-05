#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int main()
{
    fast;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m, q;
        cin >> n >> m >> q;

        vector<ll> row(q + 1);
        vector<ll> col(q + 1);

        for (ll i = 1; i <= q; i++)
        {
            cin >> row[i];
            cin >> col[i];
        }

        vector<ll> freqRow(n + 1);
        vector<ll> freqCol(m + 1);

        for (ll i = 1; i <= q; i++)
        {
            freqRow[row[i]]++;
            freqCol[col[i]]++;
        }

        ll rowEvenCnt = 0, colEvenCnt = 0, rowOddCnt = 0, colOddCnt = 0;

        for (ll i = 1; i <= n; i++)
        {
            if (freqRow[i] % 2 == 0)
                rowEvenCnt++;
            else
                rowOddCnt++;
        }
        for (ll i = 1; i <= m; i++)
        {
            if (freqCol[i] % 2 == 0)
                colEvenCnt++;
            else
                colOddCnt++;
        }

        cout << rowEvenCnt * colOddCnt + colEvenCnt * rowOddCnt << endl;
    }
    return 0;
}