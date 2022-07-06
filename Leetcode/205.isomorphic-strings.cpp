class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        int n1 = s.size(), n2 = t.size();

        if (n1 != n2)
            return false;
        int m1[256] = {0}, m2[256] = {0};

        // Using 2 maps for mapping of one another
        // If map contains non-zero value and mapping is incorrect return false, else just map
        for (int i = 0; i < n1; i++)
        {
            if ((m1[s[i]] && m1[s[i]] != t[i]) || (m2[t[i]] && m2[t[i]] != s[i]))
                return false;
            m1[s[i]] = t[i];
            m2[t[i]] = s[i];
        }
        return true;
    }
};