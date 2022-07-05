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
int find(int a)
{
    if (par[a] < 0)
        return a;
    return par[a] = find(par[a]);
}

void merge(int a, int b)
{
    a = find(a), b = find(b);
    if (a == b)
        return;
    else
    {
        par[b] = a;
    }
}

int main()
{
    int n;
    cin >> n;
    loop1(i, n)
    {
        par[i] = -1;
    }
    int q;
    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        merge(a, b);
    }
    int res = 0;
    loop1(i, n)
    {
        if (par[i] < 0)
            res++;
    }
    cout << res << endl;

    return 0;
}

// vi ar[100001];
// int vis[100001];

// void dfs(int node)
// {
//     vis[node] = 1;
//     for (auto child : ar[node])
//     {
//         if (!vis[child])
//         {
//             dfs(child);
//         }
//     }
// }

// int main()
// {
//     int n;
//     cin >> n;

//     int m;
//     cin >> m;
//     int a, b;

//     while (m--)
//     {
//         cin >> a >> b;
//         ar[a].push_back(b);
//         ar[b].push_back(a);
//     }
//     int cnt = 0;
//     loop1(i, n)
//     {
//         if (!vis[i])
//         {
//             cnt++;
//             dfs(i);
//         }
//     }
//     cout << cnt;
// }