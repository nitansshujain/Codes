#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int main()
{
    fast;
    int t;
    cin >> t;

    while (t--)
    {
        int d, c;
        cin >> d >> c;
        int day1 = 0;
        int day2 = 0;

        for (int i = 0; i < 3; i++)
        {
            int temp;
            cin >> temp;
            day1 += temp;
        }
        for (int i = 0; i < 3; i++)
        {
            int temp;
            cin >> temp;
            day2 += temp;
        }

        int without_coupon = day1 + day2 + d * 2;
        int with_coupon = 0;
        bool have_coupon = false;
        if (day1 >= 150 || day2 >= 150)
        {
            have_coupon = true;
        }
        if (day1 >= 150)
        {
            with_coupon += day1;
        }
        else
        {
            with_coupon += (day1 + d);
        }
        if (day2 >= 150)
        {
            with_coupon += day2;
        }
        else
        {
            with_coupon += (day2 + d);
        }
        if (have_coupon)
            with_coupon += c;
        if (with_coupon < without_coupon)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}