#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

int main()
{
    fast;
    int a, b;
    cin >> a >> b;

    int c = a - b;
    // string s = to_string(c);
    // if (s[s.size() - 1] != '0')
    // {
    //     s[s.size() - 1] = '0';
    // }
    // else
    // {
    //     s[s.size() - 1] = '1';
    // }
    // cout << stoi(s) << endl;

    int last_digit = c % 10;
    if (last_digit < 9)
    {
        c += 1;
    }
    else
    {
        c -= 1;
    }
    cout << c << endl;

    return 0;
}