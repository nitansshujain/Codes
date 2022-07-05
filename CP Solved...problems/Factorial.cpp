#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int number_of_zeros = 0;
        while (n)
        {
            number_of_zeros += (n / 5);
            n /= 5;
        }
        cout << number_of_zeros << endl;
    }
    return 0;
}