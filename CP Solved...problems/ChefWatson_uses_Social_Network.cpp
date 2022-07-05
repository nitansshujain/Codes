#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int main()
{
    fast;
    int n, m;
    cin >> n >> m;

    vector<pair<int, string>> special;
    vector<pair<int, string>> simple;
    unordered_set<int> seta;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        seta.insert(temp);
    }

    for (int i = 0; i < m; i++)
    {
        int f, p;
        string s;
        cin >> f >> p >> s;

        if (seta.find(f) != seta.end())
            special.push_back({p, s});
        else
            simple.push_back({p, s});
    }

    sort(special.begin(), special.end(), greater<pair<int, string>>());
    sort(simple.begin(), simple.end(), greater<pair<int, string>>());

    for (int i = 0; i < special.size(); i++)
    {
        cout << special[i].second << endl;
    }
    for (int i = 0; i < special.size(); i++)
    {
        cout << simple[i].second << endl;
    }
    return 0;
}