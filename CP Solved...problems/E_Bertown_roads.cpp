#include <bits/stdc++.h>
using namespace std;

vector<int> ar[100001];
int vis[100001];
int timer;
int in[100001], low[100001];
bool hasBridge = false;

vector<pair<int, int>> edgeList;
void dfs(int node, int par)
{
    vis[node] = 1;
    in[node] = low[node] = timer++;

    for (int child : ar[node])
    {
        if (child == par)
            continue;

        if (vis[child] == 1)
        {
            low[node] = min(low[node], in[child]); //important
            if (in[node] > in[child])              //important
            {
                edgeList.push_back({node, child});
            }
        }
        else
        {
            dfs(child, node);

            if (low[child] > in[node]) //important
            {
                hasBridge = true;
                return;
            }
            edgeList.push_back({node, child});
            low[node] = min(low[node], low[child]); // important
        }
    }
}
int main()
{
    int v, e, a, b;
    cin >> v >> e;

    while (e--)
    {
        cin >> a >> b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }

    dfs(1, -1);

    if (hasBridge)
    {
        cout << 0 << endl;
    }
    else
    {
        for (pair<int, int> e : edgeList)
        {
            cout << e.first << " " << e.second << endl;
        }
    }
    return 0;
}