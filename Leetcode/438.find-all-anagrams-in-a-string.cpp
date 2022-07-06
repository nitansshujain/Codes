class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        // Gajab Q h
        int ns = s.size();
        int np = p.size();
        int i = 0, j = 0;

        unordered_map<char, int> mp;
        for (char &c : p)
            mp[c]++;
        int mp_sz = mp.size();
        vector<int> res;
        while (j < ns)
        {
            if (mp.find(s[j]) != mp.end())
            {
                mp[s[j]]--;
                if (mp[s[j]] == 0)
                    mp_sz--;
            }

            if (j - i + 1 < np)
                j++;
            else
            {
                if (mp_sz == 0)
                {
                    res.push_back(i);
                }
                if (mp.find(s[i]) != mp.end())
                {
                    mp[s[i]]++;

                    if (mp[s[i]] == 1)
                        mp_sz++;
                }
                i++;
                j++;
            }
        }
        return res;
    }
};