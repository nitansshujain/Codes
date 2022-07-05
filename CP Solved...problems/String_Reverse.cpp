#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long int>
#define vvll vector<vector<long long int>>
#define endd '\n'
#define vpi vector<pair<int, int>>
#define vpll vector<pair<long long int, long long int>>
#define pb push_back
const int inf = 1e9 + 7;

int minop(string &s1, string &s2)
{
    int m = s1.length(), n = s2.length();

    int ans = 0;
    for (int i = n - 1, j = n - 1; i >= 0;)
    {
        while (i >= 0 && s1[i] != s2[j])
        {
            i--;
            ans++;
        }
        if (i >= 0)
        {
            i--;
            j--;
        }
    }
    return ans;
}

void solve()
{
    string s;
    cin >> s;
    string rev = s;
    reverse(rev.begin(), rev.end());
    cout << minop(rev, s);
}

int main()
{
    fast;
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endd;
    }
}
