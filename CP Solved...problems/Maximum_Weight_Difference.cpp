#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

int main()
{
    fast;
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> v;
        for (int i = 1; i <= n; i++)
        {
            int temp;
            cin >> temp;
            v.push_back(temp);
        }

        sort(v.begin(), v.end(), greater<int>());

        int total_weight = 0;
        for (auto &n : v)
        {
            total_weight += n;
        }

        int father_weight = 0;
        int son_weight = 0;
        if (n - k > k)
        {
            k = n - k;
        }

        for (int i = 0; i < k; i++)
        {
            father_weight += v[i];
            ;
        }

        son_weight = total_weight - father_weight;

        cout << father_weight - son_weight << "\n";
    }
    return 0;
}