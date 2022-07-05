#include <bits/stdc++.h>
using namespace std;

vector<int> ar[100001];
int vis[100001];
int cc_size = 0;

void dfs(int node)
{
    vis[node] = 1;
    cc_size++;

    for (int child : ar[node])
    {
        if (vis[child] == 0)
        {
            dfs(child);
        }
    }
}
int main()
{

    int t, n, m, a, b;

    cin >> t;

    while (t--)
    {
        cin >> n >> m;

        for (int i = 1; i <= n; i++)
        {
            vis[i] = 0;
            ar[i].clear();
        }

        for (int i = 1; i <= m; i++)
        {
            cin >> a >> b;
            ar[a].push_back(b);
            ar[b].push_back(a);
        }
        int cc = 0;
        long long res = 1;
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                cc_size = 0;
                dfs(i);
                cc++;

                res = (res * cc_size) % 1000000007;
            }
        }

        cout << cc << " " << res << endl;
    }
}