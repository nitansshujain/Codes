#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &v, int x, int curr)
{
    if (curr < 0)
        return -1;
    if (v[curr] == x)
        return curr;

    return solve(v, x, curr - 1);
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
    cout << solve(v, x, n - 1) << endl;
    return 0;
}