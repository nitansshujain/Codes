#include <bits/stdc++.h>
using namespace std;

vector<int> ar[10001];
int dist[10001];
int vis[10001];

vector<int> primes;

bool isPrime(int n)
{

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool isValid(int a, int b)
{
    int cnt = 0;

    while (a)
    {
        if (a % 10 != b % 10)
            cnt++;
        a /= 10;
        b /= 10;
    }

    if (cnt == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void buildGraph()
{
    for (int i = 1000; i < 9999; i++)
    {
        if (isPrime(i))
        {
            primes.push_back(i);
        }
    }

    for (int i = 0; i < primes.size(); i++)
    {
        for (int j = i + 1; j < primes.size(); j++)
        {

            int a = primes[i];
            int b = primes[j];
            if (isValid(a, b))
            {
                ar[a].push_back(b);
                ar[b].push_back(a);
            }
        }
    }
}

void bfs(int src)
{
    queue<int> q;
    vis[src] = 1;
    dist[src] = 0;
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
    int t;
    cin >> t;

    buildGraph();
    while (t--)
    {
        int a, b;
        cin >> a >> b;

        for (int i = 1000; i <= 9999; i++)
        {
            vis[i] = 0;
            dist[i] = -1;
            // ar[i].clear();
        }

        bfs(a);

        if (dist[b] == -1)
        {
            cout << "Impossible" << endl;
        }
        else
        {
            cout << dist[b] << endl;
        }
    }
    return 0;
}