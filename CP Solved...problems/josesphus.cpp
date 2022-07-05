#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int, greater<int>> mp;
    for (auto &x : v)
    {
        cin >> x;
        mp[x]++;
    }

    int res = 0;
    int upto = mp.size() / 2;
    for (auto &m : mp)
    {
        if (upto < 1)
            break;
        res += m.second;
        upto--;
    }
    cout << res << endl;

    return 0;
}
