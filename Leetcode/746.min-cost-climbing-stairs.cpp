class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // vector<int>dp(n+1);
        // dp[n]=0;
        // dp[n-1]=cost[n-1];
        // for(int i=n-2;i>=0;i--){
        //     dp[i]=min(dp[i+1],dp[i+2])+cost[i];
        // }
        // return min(dp[0],dp[1]);
        
        // Approach 2 - finding the min inplace i.e., without using dp array
        int n=cost.size(); // note: initial size of n is taken
        cost.push_back(0);
        for(int i=n-2; i>=0; i--){
            cost[i] = min(cost[i+1],cost[i+2]) + cost[i];
        }
        return min(cost[0],cost[1]);
    }
};