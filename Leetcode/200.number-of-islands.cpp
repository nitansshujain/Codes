
class Solution
{
public:
    class DSU
    {
    private:
        vector<int> root;
        vector<int> rank;

    public:
        DSU(int n) : root(n), rank(n)
        {
            for (int i = 0; i < n; i++)
            {
                root[i] = i;
                rank[i] = 1;
            }
        }

        int find(int x)
        {
            if (x == root[x])
                return x;
            return root[x] = find(root[x]);
        }

        void unionFind(int x, int y)
        {
            int rootX = find(x);
            int rootY = find(y);

            if (rootX != rootY)
            {
                if (rank[rootX] < rank[rootY])
                {
                    root[rootX] = rootY;
                }
                else if (rank[rootY] < rank[rootX])
                {
                    root[rootY] = rootX;
                }
                else
                {
                    root[rootY] = rootX;
                    rank[rootX]++;
                }
            }
        }

        bool isConnected(int x, int y)
        {
            return find(x) == find(y);
        }
    };

    int numIslands(vector<vector<char>> &grid)
    {
        // Approach 1 - using DFS
        //         int cnt=0;
        //         int N=grid.size();
        //         int M=grid[0].size();

        //         for (int i = 0; i < N; i++)
        //         {
        //             for (int j = 0; j < M; j++)
        //             {
        //                 if (grid[i][j] == '1')
        //                 {
        //                     grids(i,j,N,M,grid);
        //                     cnt++;
        //                 }
        //             }
        //         }
        //         return cnt;

        // Approach 2 - Using DSU
        int n = grid.size(), m = grid[0].size();
        DSU dsu(n * m);

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1')
                {
                    int idx1 = i * m + j;
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = i + dx[dir];
                        int ny = j + dy[dir];

                        if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == '1')
                        {
                            int idx2 = nx * m + ny;
                            dsu.unionFind(idx1, idx2);
                        }
                    }
                }
            }
        }

        unordered_set<int> seta;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1')
                {
                    int idx = i * m + j;
                    seta.insert(dsu.find(idx));
                }
            }
        }

        return seta.size();
    }
    bool isValid(int x, int y, int N, int M, vector<vector<char>> &grid)
    {
        if (x < 0 || y < 0 || x >= N || y >= M)
            return false;

        if (grid[x][y] == '0')
            return false;

        return true;
    }
    void grids(int x, int y, int N, int M, vector<vector<char>> &grid)
    {
        grid[x][y] = '0';

        // if(isValid(x-1,y,N,M,vis,grid)){
        //     grids(x-1,y,N,M,vis,grid);
        // }
        // if(isValid(x+1,y,N,M,vis,grid)){
        //     grids(x+1,y,N,M,vis,grid);
        // }
        // if(isValid(x,y-1,N,M,vis,grid)){
        //     grids(x,y-1,N,M,vis,grid);
        // }
        // if(isValid(x,y+1,N,M,vis,grid)){
        //     grids(x,y+1,N,M,vis,grid);
        // }

        // Better way to move in 4 directions
        int dir[] = {-1, 0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            if (isValid(x + dir[i], y + dir[i + 1], N, M, grid))
            {
                grids(x + dir[i], y + dir[i + 1], N, M, grid);
            }
        }
    }
};