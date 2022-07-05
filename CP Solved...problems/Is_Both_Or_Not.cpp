#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
int main()
{
    fast;
    int n;
    cin >> n;

    if (n % 5 == 0 and n % 11 == 0)
    {
        cout << "BOTH" << endl;
    }
    else if (n % 5 == 0 or n % 11 == 0)
    {
        cout << "ONE" << endl;
    }
    else
    {
        cout << "NONE" << endl;
    }

    return 0;
}