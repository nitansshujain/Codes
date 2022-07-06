class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_map<char, int> mp;
        for (char &c : s)
        {
            mp[c]++;
        }

        int res = 0;
        bool is_odd_present = false;
        for (auto m : mp)
        {
            if (m.second % 2 == 0)
                res += m.second;
            if (m.second & 1)
            {
                is_odd_present = true;
                res += (m.second - 1);
                // m.second -= (m.second-1); No need
            }
        }
        if (is_odd_present)
            res++;
        return res;
    }
};