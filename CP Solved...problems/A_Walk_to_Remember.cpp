#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vlli vector<long long int>
#define loop0(i, n) for (int i = 0; i < n; i++)
#define loop1(i, n) for (int i = 1; i <= n; i++)
#define endl '\n'
#define vpi vector<pair<int, int>>
#define vplli vector<pair<long long int, long long int>>
#define mod 1000000007

vi g[100001];
vi tg[100001];
vi SCC, order;
int vis[100001], ans[100001];

void dfs1(int node)
{
    vis[node] = 1;
    for (int child : g[node])
    {
        if (!vis[child])
        {
            dfs1(child);
        }
    }
    order.push_back(node);
}

void dfs2(int node)
{
    vis[node] = 1;
    for (int child : tg[node])
    {
        if (!vis[child])
        {
            dfs2(child);
        }
    }
    SCC.push_back(node);
}
void solve()
{
    if (SCC.size() <= 1)
        return;

    for (int node : SCC)
    {
        ans[node] = 1;
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    int a, b;
    loop1(i, m)
    {
        cin >> a >> b;
        g[a].push_back(b);
        tg[b].push_back(a);
    }

    loop1(i, n)
    {
        if (!vis[i])
        {
            dfs1(i);
        }
    }
    reverse(order.begin(), order.end());

    loop1(i, n) vis[i] = 0;

    for (int node : order)
    {
        if (!vis[node])
        {
            SCC.clear();
            dfs2(node);
            solve();
        }
    }
    loop1(i, n)
    {
        cout << ans[i] << " ";
    }
    return 0;
}