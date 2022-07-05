#include <bits/stdc++.h>
using namespace std;
#define lli long long int
string temp;
lli m;
lli pi[1000001];
void solve()
{
    m = temp.size();
    for (lli i = 1; i < m; i++)
    {
        lli j = pi[i - 1];
        while (j > 0 && temp[i] != temp[j])
            j = pi[j - 1];
        if (temp[i] == temp[j])
            j++;
        pi[i] = j;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli t;
    cin >> t;
    lli n;

    while (t--)
    {
        cin >> temp >> n;

        solve();

        cout << m + (n - 1) * (m - pi[m - 1]) << "\n";
    }

    return 0;
}