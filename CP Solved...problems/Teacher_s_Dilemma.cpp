// #include <bits/stdc++.h>
// using namespace std;

// #define vi vector<int>
// #define lli long long int
// #define vlli vector<long long int>
// #define loop0(i, n) for (int i = 0; i < n; i++)
// #define loop1(i, n) for (int i = 1; i <= n; i++)
// #define endl '\n'
// #define vpi vector<pair<int, int>>
// #define vplli vector<pair<long long int, long long int>>
// #define mod 1000000007

// vi ar[100001];
// vector<lli> SCC;
// bool vis[100001];

// void dfs(int node)
// {
//     vis[node] = 1;

//     for (int child : ar[node])
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
//     int n, m;
//     cin >> n >> m;
//     int a, b;
//     for (int i = 1; i <= m; i++)
//     {
//         cin >> a >> b;
//         ar[a].push_back(b);
//         ar[b].push_back(a);
//     }
//     lli res = 1;
//     loop1(i, n)
//     {
//         if (!vis[i])
//         {
//             SCC.clear();
//             dfs(i);
//             res = res * SCC.size();
//         }
//     }
//     cout << res << endl;
//     return 0;
// }

// Another Method:-----

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

lli parent[100001];
lli find(lli a)
{
    // while (parent[a] > 0)
    // {
    //     a = parent[a];
    // }
    // return a;

    //another method---------

    // vector<lli> v;
    // while (parent[a] > 0)
    // {
    //     v.push_back(a);
    //     a = parent[a];
    // }

    // for (int i = 0; i < v.size(); i++)
    // {
    //     parent[v[i]] = a;
    // }
    // return a;

    // another method--------

    // if (parent[a] < 0)
    //     return a;

    // int x = find(parent[a]);
    // parent[a] = x;
    // return x;

    //another method-------
    if (parent[a] < 0)
        return a;
    return parent[a] = find(parent[a]);
}
void union_(lli a, lli b)
{
    parent[a] += parent[b];
    parent[b] = a;
}

int main()
{
    lli n, m, a, b;
    cin >> n >> m;

    loop1(i, n)
    {
        parent[i] = -1;
    }

    while (m--)
    {
        cin >> a >> b;
        a = find(a), b = find(b);

        if (a != b)
            union_(a, b);
    }
    lli res = 1;

    loop1(i, n)
    {
        if (parent[i] < 0)
        {
            res = (res * abs(parent[i])) % mod;
        }
    }
    cout << res % mod << endl;
}