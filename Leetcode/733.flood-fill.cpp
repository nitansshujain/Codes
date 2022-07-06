class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int r = image.size();
        int c = image[0].size();
        int oldColor = image[sr][sc];

        vector<vector<bool>> vis(r, vector<bool>(c));
        bfs(sr, sc, image, vis, oldColor, newColor);

        return image;
    }

    void bfs(int i, int j, vector<vector<int>> &image, vector<vector<bool>> &vis, int oldColor, int newColor)
    {
        if (image[i][j] != oldColor)
            return; // No need

        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = true;

        int dir[] = {-1, 0, 1, 0, -1};
        while (!q.empty())
        {
            i = q.front().first;
            j = q.front().second;
            q.pop();

            if (image[i][j] == oldColor)
            {
                image[i][j] = newColor;
                vis[i][j] = true;

                for (int k = 0; k < 4; k++)
                {
                    int di = dir[k] + i;
                    int dj = dir[k + 1] + j;

                    if (di >= 0 && dj >= 0 && di < image.size() && dj < image[0].size())
                    {
                        if (!vis[di][dj] && image[di][dj] == oldColor)
                        {
                            q.push({di, dj});
                        }
                    }
                }
            }
        }
    }
};