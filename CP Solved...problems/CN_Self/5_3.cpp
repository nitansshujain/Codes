#include <bits/stdc++.h>
using namespace std;

int solve(int x, int n)
{
    if (n == 0)
        return 1;
    return x * solve(x, n - 1);
}

int solve1(int x, int n)
{
    int res = 1;

    while (n)
    {
        if (n & 1)
        {
            res *= x;
        }
        x *= x;
        n = n >> 1;
    }

    return res;
}
int main()
{
    int x, n;
    cin >> x >> n;

    cout << solve1(x, n) << endl;
    return 0;
}