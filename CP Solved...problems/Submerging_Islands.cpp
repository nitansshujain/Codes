#include <bits/stdc++.h>
using namespace std;

vector<int> ar[100001];
int vis[100001], in[100001], low[100001], timer;
unordered_set<int> seta;
#define endl "\n"
// int subtree_cnt=0;
void dfs(int node, int par = -1)
{
    vis[node] = 1;
    in[node] = low[node] = timer++;

    int subtree_cnt = 0;
    for (int child : ar[node])
    {
        if (child == par)
            continue;

        if (vis[child])
        {
            low[node] = min(low[node], in[child]);
        }
        else
        {
            dfs(child, node);
            subtree_cnt++;
            low[node] = min(low[node], low[child]);

            if (low[child] >= in[node] and par != -1)
            {
                seta.insert(node);
            }
        }
    }

    if (par == -1 and subtree_cnt > 1)
    {
        seta.insert(node);
    }
}
int main()
{

    int n, m, a, b;

    while (true)
    {
        cin >> n >> m;
        if (n == 0 and m == 0)
            break;

        for (int i = 1; i <= n; i++)
        {
            ar[i].clear();
            vis[i] = 0;
        }
        timer = 0;
        seta.clear();

        for (int i = 1; i <= m; i++)
        {
            cin >> a >> b;

            ar[a].push_back(b);
            ar[b].push_back(a);
        }

        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                dfs(i);
            }
        }

        cout << seta.size() << endl;
    }
    return 0;
}