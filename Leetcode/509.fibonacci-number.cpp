class Solution
{
public:
    int fib(int n)
    {
        // Approach 1 - by recursion 0(2^n)
        // vector<int>dp(n,-1);
        // return solve(n,dp);

        // Approach 2 - O(n), O(n)
        // vector<int>dp(n+1);
        //         dp[0]=0;
        //         dp[1]=1;

        //         for(int i=2;i<=n;i++){
        //             dp[i]=dp[i-1]+dp[i-2];
        //         }

        //         return dp[n];

        // Approach 3 - O(n), O(1)
        int a = 0, b = 1;
        if (n == 0)
            return a;
        int c; // for n=2
        for (int i = 2; i <= n; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return b;
    }

    int solve(int n, vector<int> &dp)
    {
        if (n == 0 or n == 1)
        {
            return n;
        }
        int a, b;
        if (dp[n - 1] != -1)
            a = dp[n - 1];
        else
            a = fib(n - 1);

        if (dp[n - 2] != -1)
            b = dp[n - 2];
        else
            b = fib(n - 2);
        dp[n - 1] = a, dp[n - 2] = b;
        return a + b;
    }
};