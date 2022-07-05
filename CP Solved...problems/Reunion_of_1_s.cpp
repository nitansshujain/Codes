// LOD-3 LOD-3 LOD-3 LOD-3 LOD-3
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define lli long long int
#define vlli vector<long long int>
#define loop0(i, n) for (int i = 0; i < n; i++)
#define loop1(i, n) for (int i = 1; i <= n; i++)
#define endl '\n'
#define vpi vector<pair<int, int>>
#define vplli vector<pair<long long int, long long int>>
#define mod 1000000007
int par[100001];
int r[100001];
char ar[100001];

int find(int a)
{
    if (par[a] < 0)
        return a;
    return par[a] = find(par[a]);
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a == b)
        return;

    if (r[a] > r[b])
    {
        r[a] += r[b];
        par[b] = a;
    }
    else
    {
        r[b] += r[a];
        par[a] = b;
    }
}
int main()
{
    int n, q;
    int mx = 0;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
    {
        cin >> ar[i];
        if (ar[i] == '1')
        {
            par[i] = -1;
            r[i] = 1;

            if (i > 1 and ar[i - 1] == '1')
                merge(i, i - 1);

            int p = find(i);
            if (r[p] > mx)
                mx = r[p];
        }
    }

    while (q--)
    {
        int a;
        cin >> a;

        if (a == 1)
            cout << mx << endl;

        else
        {
            cin >> a;
            if (ar[a] == '1')
                continue;

            ar[a] = '1';
            par[a] = -1;
            r[a] = 1;

            if (a > 1 and ar[a - 1] == '1')
                merge(a, a - 1);
            if (a < n and ar[a + 1] == '1')
                merge(a, a + 1);

            int p = find(a);
            if (r[p] > mx)
                mx = r[p];
        }
    }
    return 0;
}