class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        // Approach 1 - O(N), O(N)
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> arr(m + n - 1);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                arr[i + j].push_back(mat[i][j]);
            }
        }
        vector<int> ans;
        for (int i = 0; i < m + n - 1; i++)
        {
            if (i % 2 != 0)
                ans.insert(ans.end(), arr[i].begin(), arr[i].end());
            else
                ans.insert(ans.end(), arr[i].rbegin(), arr[i].rend());
        }
        return ans;

        // Approach 2 - O(N), O(1)
        int m = mat.size();
        int n = mat[0].size();
        vector<int> res;

        for (int s = 0; s < m + n - 1; s++)
        {
            // for all i + j = s
            for (int x = 0; x <= s; x++)
            {
                int i = x;
                int j = s - i;
                if (s % 2 == 0)
                    swap(i, j);

                if (i >= m || j >= n)
                    continue;

                res.push_back(mat[i][j]);
            }
        }
        return res;
    }
};