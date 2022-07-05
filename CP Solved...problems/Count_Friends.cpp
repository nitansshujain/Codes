#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int>
#define lli long long int
#define vlli vector<long long int>
#define loop0(i, n) for (int i = 0; i < n; i++)
#define loop1(i, n) for (int i = 1; i <= n; i++)
#define endl '\n'
#define vpi vector<pair<int, int>>
#define vplli vector<pair<long long int, long long int>>
#define mod 1000000007

int par[1000001];
int r[100001];
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
}
int main()
{
    int n, m;
    cin >> n >> m;

    loop1(i, n)
    {
        par[i] = -1;
        r[i] = 1;
    }

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        merge(a, b);
    }

    loop1(i, n)
    {
        int par = find(i);
        cout << r[par] - 1 << " ";
    }
}
// bool vis[100001];
// vi ar[100001];
// vi SCC;
// void dfs(int node)
// {
//     vis[node] = true;
//     for (auto child : ar[node])
//     {
//         if (!vis[child])
//         {
//             dfs(child);
//         }
//     }
//     SCC.push_back(node);
// }
// int main()
// {
//     fast;
//     int n, m, a, b;
//     cin >> n >> m;
//     vector<int> res(n, 0);
//     loop1(i, m)
//     {
//         cin >> a >> b;
//         ar[a].push_back(b);
//         ar[b].push_back(a);
//     }

//     loop1(i, n)
//     {
//         if (!vis[i])
//         {
//             SCC.clear();
//             dfs(i);
//             for (int i = 0; i < SCC.size(); i++)
//             {
//                 res[SCC[i]] = SCC.size() - 1;
//             }
//         }
//     }

//     loop1(i, res.size())
//     {
//         cout << res[i] << " ";
//     }
//     return 0;
// }