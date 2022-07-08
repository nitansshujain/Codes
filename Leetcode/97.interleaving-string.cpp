class Solution
{
public:
    bool isInterleave(string a, string b, string c)
    {
        // This approach will fail. eg. take s1 = xy, s2 = zyb and res = xzyby. if we match elements of s1 first then it would return false. It's a greedy approach which will pass for all distinct chars in strings.
        //         int an = a.size();
        //         int bn = b.size();
        //         int cn = c.size();
        //         if(an + bn != cn) return false;

        //         int i=0,j=0,k=0;
        //         while(k<cn){
        //             if(i<an && a[i] == c[k]) i++;
        //             else if(j<bn && b[j] == c[k]) j++;
        //             else break;
        //             k++;
        //         }
        //         if(i<an || j<bn) return false;
        //         return true;

        // Approach -> since we can use any of s1/s2 to get res to get optimal res, we use DP
        int an = a.size();
        int bn = b.size();
        int cn = c.size();
        if (an + bn != cn)
            return 0;

        vector<vector<int>> dp(an + 1, vector<int>(bn + 1, -1));
        return solve(a, b, c, an, bn, cn, dp);
    }

    bool solve(string &a, string &b, string &c, int an, int bn, int cn, vector<vector<int>> &dp)
    {
        if (cn == 0)
            return 1;
        if (dp[an][bn] != -1)
            return dp[an][bn];

        int A = 0, B = 0;

        if (an - 1 >= 0 && a[an - 1] == c[cn - 1])
            A = solve(a, b, c, an - 1, bn, cn - 1, dp);
        if (bn - 1 >= 0 && b[bn - 1] == c[cn - 1])
            B = solve(a, b, c, an, bn - 1, cn - 1, dp);
        return dp[an][bn] = A || B;
    }
};