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

int main()
{
    fast;
    ll n;
    cin >> n;
    ll odd_cnt = 0, even_cnt = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        ll x;
        cin >> x;
        if (x & 1)
            odd_cnt++;
        else
            even_cnt++;
    }
    if (odd_cnt & 1)
        cout << "NO" << endd;
    else
        cout << "YES" << endd;
}
