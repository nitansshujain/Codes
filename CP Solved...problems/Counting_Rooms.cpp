#include <bits/stdc++.h>
using namespace std;

bool vis[1001][1001];
char ar[1001][1001];
int N, M;

bool isValid(int x, int y)
{
    if (x < 1 || y < 1 || x > N || y > M)
        return false;

    if (vis[x][y] == 1 || ar[x][y] == '#')
        return false;

    return true;
}
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
void grid(int x, int y)
{
    vis[x][y] = 1;

    for (int i = 0; i < 4; i++)
    {
        if (isValid(x + dx[i], y + dy[i]))
        {
            grid(x + dx[i], y + dy[i]);
        }
    }
}
int main()
{
    cin >> N >> M;
    int cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> ar[i][j];
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (vis[i][j] == 0 and ar[i][j] == '.')
            {
                grid(i, j);
                cnt++;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}