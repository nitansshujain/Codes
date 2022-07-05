#include <bits/stdc++.h>
using namespace std;

vector<int> ar[1000001];
int vis[1000001], cc[1000001];

int curr_cc; // int curr_cc;

void dfs(int node)
{
    vis[node] = 1;
    cc[node] = curr_cc; //IMPORTANT

    for (int child : ar[node])
    {
        if (!vis[child])
        {
            dfs(child);
        }
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int v, e;
        cin >> v >> e;

        for (int i = 1; i <= v; i++)
        {
            vis[i] = 0;
            ar[i].clear();
        }
        string s;
        int a, b;

        vector<pair<int, int>> notEqualvala;
        for (int i = 1; i <= e; i++)
        {
            cin >> a >> s >> b;

            if (s == "=")
            {
                ar[a].push_back(b);
                ar[b].push_back(a);
            }
            else
            {
                notEqualvala.push_back({a, b});
            }
        }

        curr_cc = 0; // IMPORTANT

        for (int i = 1; i <= v; i++)
        {
            if (!vis[i])
            {
                curr_cc++;
                dfs(i);
            }
        }

        bool flag = true;

        for (int i = 0; i < notEqualvala.size(); i++)
        {
            int x = notEqualvala[i].first;
            int y = notEqualvala[i].second;

            if (cc[x] == cc[y])
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}