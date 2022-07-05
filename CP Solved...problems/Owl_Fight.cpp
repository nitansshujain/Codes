#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define lli long long int
#define vlli vector<long long int>
#define loop0(i, n) for (int i = 0; i < n; i++)
#define loop1(i, n) for (int i = 1; i <= n; i++)
#define end '\n'
#define vpi vector<pair<int, int>>
#define vplli vector<pair<long long int, long long int>>
#define mod 1000000007

int par[100001];

int find(int a)
{
    if (par[a] < 0)
        return a;
    return par[a] = find(par[a]);
}
void union_(int a, int b)
{
    par[a] = min(par[a], par[b]);
    par[b] = a;
}
int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        par[i] = -i;
    }
    int a, b;
    while (m--)
    {
        cin >> a >> b;
        a = find(a), b = find(b);
        if (a != b)
            union_(a, b);
    }

    int q;
    cin >> q;

    while (q--)
    {
        cin >> a >> b;
        int x, y;
        x = a, y = b;
        a = find(a), b = find(b);
        if (a == b)
            cout << "TIE" << endl;
        else
        {
            if (par[a] < par[b])
                cout << x << endl; //reciprocal due to -ve value
            else
                cout << y << endl;
        }
    }
    return 0;
}