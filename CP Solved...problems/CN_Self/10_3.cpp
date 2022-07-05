#include <bits/stdc++.h>
using namespace std;

void solve(string &s, int curr)
{
    if (s.size() <= 1)
        return;
    if (curr == s.size() || s[curr] == '\0')
        return;
    if (curr + 1 < s.size())
    {
        if (s[curr] == s[curr + 1])
        {
            int i = curr;
            while (s[i])
            {
                s[i] = s[i + 1];
                i++;
            }
            s[i] = '\0';
            // cout << s << endl;
            solve(s, curr);
        }
        else
        {
            // cout << s << endl;
            solve(s, curr + 1);
        }
    }
}

// Better
void solve1(string &s, int i, string &res)
{
    if (s.size() == i)
        return;

    if (s[i + 1] && s[i] != s[i + 1])
    {
        res.push_back(s[i]);
    }
    else
    {
        while (s[i + 1] && s[i] == s[i + 1])
        {
            i++;
        }
        res.push_back(s[i]);
    }
    solve1(s, i + 1, res);
}
int main()
{
    string s;
    cin >> s;

    // solve(s, 0);
    // cout << s << endl;

    string res = "";
    solve1(s, 0, res);
    cout << res << endl;
    return 0;
}