#include <bits/stdc++.h>
using namespace std;

char ar[31][31];
bool vis[31][31];
int dis[31][31];
int n;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

bool isValid(int x, int y)
{
    if (x < 1 || y < 1 || x > n || y > n)
        return false;

    if (vis[x][y] || ar[x][y] == 'T')
        return false;

    return true;
}

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = 1;
    dis[x][y] = 0;

    while (!q.empty())
    {
        int a = q.front().first;
        int b = q.front().second;
        int d = dis[a][b];
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int newA = a + dx[i];
            int newB = b + dy[i];

            if (isValid(newA, newB))
            {
                dis[newA][newB] = d + 1;
                vis[newA][newB] = 1;
                q.push({newA, newB});
            }
        }
    }
}
int main()
{
    int srcX, srcY;
    int destX, destY;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> ar[i][j];
            if (ar[i][j] == 'S')
            {
                srcX = i, srcY = j;
            }
            if (ar[i][j] == 'E')
            {
                destX = i, destY = j;
            }
        }
    }
    bfs(srcX, srcY);

    cout << dis[destX][destY] << endl;
    return 0;
}