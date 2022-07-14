class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        vector<string> part;
        help(s, 0, part, res);
        return res;
    }

    void help(string s, int idx, vector<string> &part, vector<vector<string>> &res)
    {
        if (idx == s.size())
        {
            res.push_back(part);
            return;
        }

        for (int i = idx; i < s.size(); i++)
        {
            if (isPalin(s, idx, i))
            {
                part.push_back(s.substr(idx, i - idx + 1));
                help(s, i + 1, part, res);
                part.pop_back();
            }
        }
    }

    bool isPalin(string s, int st, int en)
    {
        while (st < en)
        {
            if (s[st++] != s[en--])
            {
                return false;
            }
        }
        return true;
    }
};