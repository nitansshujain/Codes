#include <bits/stdc++.h>
using namespace std;

bool vis[9][9];
int dist[9][9];

int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int targetX, targetY;
int getX(char a)
{
    return a - 'a' + 1;
}

bool isValid(int x, int y)
{
    if (x < 1 || y < 1 || x > 8 || y > 8)
        return false;
    if (vis[x][y])
        return false;

    return true;
}

int bfs(int x, int y)
{
    vis[x][y] = 1;
    dist[x][y] = 0;
    queue<pair<int, int>> q;
    q.push({x, y});
    if (x == targetX and y == targetY)
        return dist[x][y];

    while (!q.empty())
    {
        int curr_x = q.front().first;
        int curr_y = q.front().second;
        q.pop();
        int d = dist[curr_x][curr_y];

        for (int i = 0; i < 8; i++)
        {
            if (isValid(curr_x + dx[i], curr_y + dy[i]))
            {
                x = curr_x + dx[i];
                y = curr_y + dy[i];
                dist[x][y] = d + 1;
                vis[x][y] = 1;
                q.push({x, y});

                if (x == targetX and y == targetY)
                    return dist[x][y];
            }
        }
    }
    return 0;
}

int main()
{
    int x, y, t;
    cin >> t;
    while (t--)
    {
        char a, b;

        for (int i = 1; i <= 8; i++)
        {
            for (int j = 1; j <= 8; j++)
            {
                vis[i][j] = 0;
            }
        }
        cin >> a >> b;
        x = getX(a);
        y = b - '0';

        cin >> a >> b;
        targetX = getX(a);
        targetY = b - '0';

        cout << bfs(x, y) << endl;
    }
    return 0;
}