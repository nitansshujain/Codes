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

        vector<int> v{100, 50, 10, 5, 2, 1};
        int notes_cnt = 0;
        for (int i = 0; i < 6; i++)
        {
            notes_cnt += (n / v[i]);
            n %= v[i];
            if (n == 0)
                break;
        }
        cout << notes_cnt << endl;
    }

    return 0;
}