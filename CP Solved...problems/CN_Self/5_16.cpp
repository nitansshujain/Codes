#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &v, int x, int curr, vector<int> &res)
{
    if (curr == v.size())
        return;
    if (v[curr] == x)
        res.push_back(curr);

    solve(v, x, curr + 1, res);
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;

    int x;
    cin >> x;
    vector<int> res;
    solve(v, x, 0, res);

    for (auto &x : res)
        cout << x << " ";
    return 0;
}