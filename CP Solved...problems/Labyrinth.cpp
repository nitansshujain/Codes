#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

bool valid(int x, int y, int n, int m)
{
    if (x < 0 || y < 0 || x >= n || y >= m)
        return false;

    return true;
}

int main()
{
    int t = 1;
    // cin>>t;
    while (t--)
    {
        //U D L R
        int row[] = {-1, 1, 0, 0};
        int col[] = {0, 0, -1, 1};

        int n, m;
        cin >> n >> m;

        vector<vector<char>> v(n, vector<char>(m));
        int vis[n][m];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                vis[i][j] = 0;
            }
        }

        pair<int, int> start;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> v[i][j];
                if (v[i][j] == 'A')
                {
                    start = make_pair(i, j);
                }
            }
        }
        queue<pair<int, int>> q;
        vis[start.first][start.second] = 1;
        q.push(start);

        map<pair<int, int>, pair<pair<int, int>, char>> parent;

        while (!q.empty())
        {
            int a = q.front().first;
            int b = q.front().second;

            q.pop();

            for (int i = 0; i < 4; i++)
            {
                if (valid(a + row[i], b + col[i], n, m) and vis[a + row[i]][b + col[i]] == 0 and (v[a + row[i]][b + col[i]] == '.' or v[a + row[i]][b + col[i]] == 'B'))
                {
                    char c;
                    if (i == 0)
                        c = 'U';
                    else if (i == 1)
                        c = 'D';
                    else if (i == 2)
                        c = 'L';
                    else if (i == 3)
                        c = 'R';

                    parent[{a + row[i], b + col[i]}] = {{a, b}, c};

                    if (v[a + row[i]][b + col[i]] == 'B')
                    {
                        pair<int, int> end = {a + row[i], b + col[i]};
                        string res = "";
                        while (true)
                        {
                            res += parent[end].second;
                            end = parent[end].first;
                            if (end.first == start.first and end.second == start.second)
                                break;
                        }

                        reverse(res.begin(), res.end());
                        cout << "YES" << endl;
                        cout << res.length() << endl;
                        cout << res << endl;
                        return 0;
                    }
                    vis[a + row[i]][b + col[i]] = 1;
                    q.push({a + row[i], b + col[i]});
                }
            }
            // for (auto i : row)
            // {
            //     for (auto j : col)
            //     {
            //         if (valid(a + i, b + j, n, m) and abs(i) != abs(j) and vis[a + i][b + j] == 0 and (v[a + i][b + j] == '.' or v[a + i][b + j] == 'B'))
            //         {
            //             char c;
            //             if (i == 1 and j == 0)
            //                 c = 'D';
            //             else if (i == -1 and j == 0)
            //                 c = 'U';
            //             else if (j == 1 and i == 0)
            //                 c = 'R';
            //             else if (j == -1 and i == 0)
            //                 c = 'L';

            //             parent[{a + i, b + j}] = {{a, b}, c};

            //             if (v[a + i][b + j] == 'B')
            //             {
            //                 pair<int, int> end = {a + i, b + j};
            //                 string res = "";
            //                 while (true)
            //                 {
            //                     res += parent[end].second;
            //                     end = parent[end].first;
            //                     if (end.first == start.first and end.second == start.second)
            //                         break;
            //                 }

            //                 reverse(res.begin(), res.end());
            //                 cout << "YES" << endl;
            //                 cout << res.length() << endl;
            //                 cout << res << endl;
            //                 return 0;
            //             }
            //             vis[a + i][b + j] = 1;
            //             q.push({a + i, b + j});
            //         }
            //     }
            // }
        }
        cout << "NO" << endl;
    }
    return 0;
}
