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
        string s;
        cin >> s;
        bool is_present = false;
        // for (int i = 0; i < s.size() - 2; i++)
        // {
        //     if (s.substr(i, 3) == "010" || s.substr(i, 3) == "101")
        //     {
        //         is_present = true;
        //         break;
        //     }
        // }

        // if (is_present)
        //     cout << "Good" << endl;
        // else
        //     cout << "Bad" << endl;

        //Approach 2
        // for (int i = 1; i < s.size() - 1; i++)
        // {
        //     if (s[i] == '1')
        //     {
        //         if (s[i - 1] == '0' && s[i + 1] == '0')
        //         {
        //             is_present = true;
        //             break;
        //         }
        //     }
        //     else
        //     {
        //         if (s[i - 1] == '1' && s[i + 1] == '1')
        //         {
        //             is_present = true;
        //             break;
        //         }
        //     }
        // }

        // cout << (is_present ? "Good" : "Bad") << "\n";

        //Approach 3
        string check1 = "010";
        string check2 = "101";

        if (s.find(check1) != string::npos || s.find(check2) != string::npos)
            is_present = true;
        cout << (is_present ? "Good" : "Bad") << "\n";
    }
    return 0;
}