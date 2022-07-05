#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

int main()
{
    fast;
    int n;
    cin >> n;
    vector<int> factors;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            factors.push_back(i);
        }
    }

    cout << factors.size() << "\n";
    for (auto f : factors)
    {
        cout << f << " ";
    }
    return 0;
}