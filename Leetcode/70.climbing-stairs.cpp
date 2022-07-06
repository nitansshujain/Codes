class Solution {
public:
    int climbStairs(int n) {
        // Approach 1 - O(n), O(n)
//         vector<int>dp(n+1);
//         dp[0]=1;
//         dp[1]=1;
        
//         for(int i=2;i<=n;i++){
//             dp[i]=dp[i-1]+dp[i-2];
//         }
        
//         return dp[n];
        
        // Approach 2 - O(n), O(1) similar to fibocanni series
        int a = 1, b = 1;
        int c; // for n=2
        for(int i=2;i<=n;i++){
            c = a+b;
            a = b;
            b = c;
        }
        return b;
    }
};