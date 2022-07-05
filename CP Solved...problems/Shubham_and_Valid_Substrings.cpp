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

    int t = 1;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        int cnt = 1, mx = 1;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] - s[i - 1] == 1)
            {
                cnt++;
                mx = max(mx, cnt);
            }
            else
            {
                cnt = 1;
            }
        }
        cout << mx << endl;
    }
    return 0;
}