#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

int main()
{
    fast;
    int t;
    cin >> t;

    while (t--)
    {
        string in;
        cin >> in;
        int in_n = in.size();

        string is;
        cin >> is;
        int is_n = is.size();

        int result_cnt = 0;
        for (int i = 0; i < is_n; i++)
        {
            if (in.find(is[i]) != string::npos)
            {
                result_cnt++;
            }
        }

        cout << result_cnt << "\n";
    }
    return 0;
}