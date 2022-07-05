#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int z;
    cin >> z;

    vector<int> v(n);
    vector<pair<int, int>> res;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        int diff = abs(v[i] - z);
        res.push_back({diff, v[i]});
    }

    sort(res.begin(), res.end());

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i].second << " ";
    }

    cout << endl;
    return 0;
}