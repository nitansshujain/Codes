#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

const int V = 1e5 + 10;
vector<pair<int, int>> adj[V];
const int inf = 1e9 + 7;
vector<int> level(V, inf);
void bfs0_1()
{
    deque<int> q;
    q.push_back(1);
    level[1] = 0;

    while (!q.empty())
    {
        int par = q.front();
        q.pop_front();
        for (auto child : adj[par])
        {
            int v = child.first;
            int w = child.second;

            if (level[par] + w < level[v])
            {
                level[v] = level[par] + w;
                if (w == 1) // penalty of 1 and push in the front
                    q.push_front(v);
                else
                    q.push_back(v);
            }
        }
    }
}
int main()
{
    fast;
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        ll n, e;
        cin >> n >> e;

        int a, b;
        for (int i = 1; i <= e; i++)
        {
            cin >> a >> b;
            if (a == b) //self loops
                continue;
            adj[a].push_back({b, 0}); // normal push
            adj[b].push_back({a, 1}); // push with penalty
        }

        bfs0_1();

        cout << (level[n] == inf ? -1 : level[n]) << endl;
    }
    return 0;
}