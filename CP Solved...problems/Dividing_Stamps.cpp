#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int main()
{
    fast;
    int n;
    cin >> n;

    // vector<int>v;
    int total_sum = 0;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        total_sum += temp;
    }

    int member_wise_stamps = n * (n + 1) / 2;

    cout << (total_sum == member_wise_stamps ? "YES" : "NO")
         << endl;

    return 0;
}