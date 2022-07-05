#include <bits/stdc++.h>
using namespace std;

#define nitro ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int>
#define lli long long int
#define vlli vector<long long int>
#define loop0(i, n) for (int i = 0; i < n; i++)
#define loop1(i, n) for (int i = 1; i <= n; i++)
#define endl '\n'
#define vpi vector<pair<int, int>>
#define vplli vector<pair<long long int, long long int>>
#define mod 1000000007

lli ar[101][101], I[101][101];
void mul(lli A[][101], lli B[][101], lli dim)
{
    lli res[dim + 1][dim + 1];
    loop1(i, dim)
    {
        loop1(j, dim)
        {
            res[i][j] = 0;
            loop1(k, dim)
            {
                res[i][j] = (res[i][j] + (A[i][k] % mod * B[k][j] % mod) % mod) % mod;
            }
        }
    }
    loop1(i, dim) loop1(j, dim) A[i][j] = res[i][j];
}
void power(lli A[][101], lli dim, lli n)
{
    loop1(i, dim) loop1(j, dim)
    {
        if (i == j)
            I[i][j] = 1;
        else
            I[i][j] = 0;
    }

    // loop1(i, n)
    // {
    //     mul(I, A, dim);
    // }

    while (n)
    {
        if (n % 2 == 1)
        {
            mul(I, A, dim), n--;
        }
        else
        {
            mul(A, A, dim), n /= 2;
        }
    }
    loop1(i, dim) loop1(j, dim) ar[i][j] = I[i][j];
}

void printMat(lli A[][101], lli dim)
{
    loop1(i, dim)
    {
        loop1(j, dim)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    nitro;
    lli t = 1;
    cin >> t;
    while (t--)
    {
        lli dim, n;
        cin >> dim >> n;

        loop1(i, dim) loop1(j, dim) cin >> ar[i][j];

        power(ar, dim, n);
        printMat(ar, dim);
    }
}