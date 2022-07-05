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

int ar[32];
int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int x;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            for (int j = 0; j < 32; j++)
            {
                if (x & (1 << j))
                {
                    ar[j]++;
                }
            }
        }
        int curr = 0;
        for (int i = 1; i < 32; i++)
        {
            if (ar[i] > ar[curr])
            {
                curr = i;
            }
        }
        cout << curr << endl;
    }
}