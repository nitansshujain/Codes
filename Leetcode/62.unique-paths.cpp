class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        //          Approach 1 - Top Down (Recur + Momos)
        // vector<vector<int>>dp(m,vector<int>(n,-1));
        // return solve(m-1,n-1,dp);

        //          Approach 2 - Bottom Up (Tabulation)
        //         vector<vector<int>>dp(m,vector<int>(n,0));
        //         dp[0][0]=1;

        //         for(int i=0;i<m;i++){
        //             for(int j=0;j<n;j++){
        //                 if(i==0 && j==0) continue;

        //                 int left=0,up=0;
        //                 if(j>=1) left = dp[i][j-1];
        //                 if(i>=1) up = dp[i-1][j];

        //                 dp[i][j] = left + up;
        //             }
        //         }

        //         return dp[m-1][n-1];

        // Approach 3 - Combinatorics
        // https://www.youtube.com/watch?v=t_f0nwwdg5o&ab_channel=takeUforward
        int N = m + n - 2;         // total possibility - row me (m-1) moves, similarly col me (n-1) moves possible
        int r = min(m - 1, n - 1); // or r = n-1 or r = m-1

        double res = 1.0; // double is taken for precision

        // for(int i=1;i<=r;i++){
        //     res = res*(N-r+i)/i;
        // }
        // OR
        for (int i = 0; i < r; i++)
        {
            res = res * (N - i) / (i + 1);
        }
        return (int)(res + 0.5); // if decimal is >=0.5 then ceil value otherwise floor
    }

    int solve(int i, int j, vector<vector<int>> &dp)
    {
        if (i == 0 && j == 0)
            return 1;
        if (i < 0 || j < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];
        int left = solve(i, j - 1, dp);
        int up = solve(i - 1, j, dp);

        return dp[i][j] = left + up;
    }
};