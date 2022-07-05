#include <bits/stdc++.h>
using namespace std;

vector<int> ar[10001];
int vis[10001];
int dist[10001];

void bfs(int src)
{
    vis[src] = 1;
    dist[src] = 0;
    queue<int> q;
    q.push(src);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int child : ar[curr])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = 1;
                dist[child] = dist[curr] + 1;
            }
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
            ar[i].clear();
            vis[i] = 0;
            dist[i] = 0;
        }

        for (int i = 1; i <= m; i++)
        {
            cin >> a >> b;
            ar[a].push_back(b);
            ar[b].push_back(a);
        }

        bfs(1);

        cout << dist[n] << endl;
    }
}