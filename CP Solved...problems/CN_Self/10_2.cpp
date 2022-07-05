#include <bits/stdc++.h>
using namespace std;

void solve(string &s, char from, char to, int curr)
{
    if (curr == s.size())
        return;
    if (s[curr] == from)
        s[curr] = to;
    solve(s, from, to, curr + 1);
}

int main()
{
    string s;
    cin >> s;
    char from, to;
    cin >> from >> to;

    solve(s, from, to, 0);
    cout << s << endl;
    return 0;
}