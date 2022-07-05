#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vlli vector<long long int>
#define loop0(i, n) for (int i = 0; i < n; i++)
#define loop1(i, n) for (int i = 1; i <= n; i++)
#define endl '\n'
#define vpi vector<pair<int, int>>
#define vplli vector<pair<long long int, long long int>>
#define pb push_back
#define mod 1000000007

vi ar[1000001];
vi tr[1000001];
vi order;
vi SCC;

int val[1000001], vis[1000001];
void dfs1(int node)
{
    vis[node] = 1;

    for (int child : ar[node])
    {
        if (!vis[child])
        {
            dfs1(child);
        }
    }
    order.pb(node);
}

void dfs2(int node)
{
    vis[node] = 1;

    for (int child : tr[node])
    {
        if (!vis[child])
        {
            dfs2(child);
        }
    }
    SCC.pb(node);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a, b;
        int res = 0;
        loop0(i, n)
        {
            ar[i].clear();
            tr[i].clear();
            val[i] = 0;
            vis[i] = 0;
        }
        order.clear();
        SCC.clear();

        loop0(i, n)
        {
            cin >> val[i];
            a = i;
            b = (i + val[i] + 1) % n;

            ar[a].pb(b);
            tr[b].pb(a);
        }

        loop0(i, n)
        {
            if (!vis[i])
            {
                dfs1(i);
            }
        }
        loop0(i, n)
        {
            vis[i] = 0;
        }

        reverse(order.begin(), order.end());

        for (int node : order)
        {
            if (!vis[node])
            {
                SCC.clear();
                dfs2(node);
                if (SCC.size() == 1 and SCC[0] != ar[SCC[0]][0]) //important
                    continue;

                res += SCC.size();
            }
        }
        cout << res << endl;
    }
}