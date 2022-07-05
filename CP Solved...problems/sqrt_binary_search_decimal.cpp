#include <bits/stdc++.h>
using namespace std;

int sqrtInteger(long long x)
{
    long long int s = 1, e = x;
    long long res = 0;

    while (s <= e)
    {
        long long int mid = s + (e - s) / 2;

        if (mid * mid == x)
            return mid;
        else if (mid * mid > x)
            e = mid - 1;
        else
        {
            res = mid;
            s = mid + 1;
        }
    }

    return (int)res;
}

double sqrtDouble(int x, int temp_res, int precision)
{
    double factor = 1;
    double res = temp_res;
    for (int i = 1; i <= precision; i++)
    {
        factor /= 10;
        for (double j = temp_res; j * j < x; j += factor)
        {
            res = j;
        }
    }
    return res;
}
int main()
{
    cout << "Enter a number to find square Root: ";
    int n;
    cin >> n;
    int temp_res = sqrtInteger(n);
    // cout << temp_res << endl;
    double res = sqrtDouble(n, temp_res, 3);
    cout << res << endl;
    return 0;
}