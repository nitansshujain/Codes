#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int main()
{
    fast;
    int n;
    cin >> n;

    // vector<int>v;
    int odd_cnt = 0, even_cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (temp % 2 == 0)
            even_cnt++;
        else
            odd_cnt++;
        // v.push_back(temp);
    }

    if (even_cnt > odd_cnt)
        cout << "READY FOR BATTLE" << endl;
    else
        cout << "NOT READY" << endl;
    return 0;
}