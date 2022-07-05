#include <bits/stdc++.h>
using namespace std;

vector<int> ar[10001];
vector<int> res;
int in[10001];
#define endl "\n"
bool kahn(int n)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
        {
            pq.push(i);
        }
    }

    while (!pq.empty())
    {
        int curr = pq.top();
        pq.pop();
        res.push_back(curr);

        for (int node : ar[curr])
        {
            in[node]--;
            if (in[node] == 0)
            {
                pq.push(node);
            }
        }
    }

    return res.size() == n;
}
int main()
{
    int n, m, a, b;

    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        ar[a].push_back(b);
        in[b]++;
    }

    if (!kahn(n))
    {
        cout << "Sandro fails." << endl;
    }
    else
    {
        for (int x : res)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}