class Solution
{
public:
    string longestPalindrome(string s)
    {
        // Approach 1 - pepcoding
        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));
        string res = "";
        int res_len = 0;
        int temp_len = 0;
        for (int g = 0; g < n; g++)
        {
            for (int i = 0, j = g; j < n; i++, j++)
            {
                if (g == 0)
                {
                    dp[i][j] = 1;
                }
                else if (g == 1)
                {
                    if (s[i] == s[j])
                        dp[i][j] = 1;
                    else
                        dp[i][j] = 0;
                }
                else
                {
                    if (s[i] == s[j] && dp[i + 1][j - 1] == true)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = 0;
                }

                if (dp[i][j] == true)
                {
                    temp_len = g + 1;
                    if (temp_len > res_len)
                    {
                        res_len = temp_len;
                        res = s.substr(i, j - i + 1);
                    }
                }
            }
        }

        return res;

        // Approach 2
        // https://www.youtube.com/watch?v=jCOJk4UyO8w&list=PLDdcY4olLQk0A0o2U0fOUjmO2v3X6GOxX&index=5&ab_channel=CodeLibrary-byYogesh%26Shailesh
        int len = 0;
        int start = 0;
        int l;
        int r;
        // even case
        for (int i = 0; i < S.length() - 1; i++)
        {
            l = i;
            r = i + 1;
            while (l >= 0 && r < S.length() && S[l] == S[r])
            {
                if (r - l + 1 > len)
                {
                    len = r - l + 1;
                    start = l;
                }
                l--;
                r++;
            }
        }

        // odd case
        for (int i = 1; i < S.length() - 1; i++)
        {
            l = i - 1;
            r = i + 1;
            while (l >= 0 && r < S.length() && S[l] == S[r])
            {
                if (r - l + 1 > len)
                {
                    len = r - l + 1;
                    start = l;
                }
                l--;
                r++;
            }
        }
        if (len == 0)
        {
            len++;
        }
        return S.substr(start, len);
    }
};