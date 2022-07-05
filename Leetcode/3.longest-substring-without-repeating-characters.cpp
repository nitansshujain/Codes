class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        // Approach 1
        int res = 0;
        unordered_set<char> seta;
        int i = 0, j = 0;
        while (j < s.size())
        {
            if (seta.find(s[j]) == seta.end())
            {
                seta.insert(s[j++]);
                if (seta.size() > res)
                {
                    res = seta.size();
                }
                // res=max(res,seta.size());
                // j++;
            }
            else
            {
                seta.erase(s[i]);
                i++;
            }
        }
        return res;

        // Approach 2
        int store[256] = {0}; // array to store the occurences of all the characters
        int l = 0;            // left pointer
        int r = 0;            // right pointer
        int ans = 0;          // initializing the required length as 0

        while (r < s.length()) // iterate over the string till the right pointer reaches the end of the string
        {
            store[s[r]]++; // increment the count of the character present in the right pointer

            while (store[s[r]] > 1) // if the occurence become more than 1 means the char is repeated
            {
                store[s[l]]--; // reduce the occurence of temp as it might be present ahead also in the string
                l++;           // contraction of the present window till the occurence of the 't' char becomes 1
            }

            ans = max(ans, r - l + 1); // As the index starts from 0 , ans will be (right pointer-left pointer + 1)
            r++;                       // now will increment the right pointer
        }
        return ans;

        // Approach 4 - similar to k unique chars, but here we need all unique means window has all the unique chars, means size of window(j-i+1) has all uniqe
        int res = 0;
        unordered_map<char, int> mp;
        int i = 0, j = 0, n = s.size(), ws = 0;
        while (j < n)
        {
            mp[s[j]]++;
            ws = j - i + 1; // window size
            if (mp.size() > ws)
                j++; // No need since unique chars(mp.size()) can be at max ws
            else if (mp.size() == ws)
            {
                res = max(res, ws);
                j++;
            }
            else
            {
                while (mp.size() < ws)
                {
                    mp[s[i]]--;
                    if (mp[s[i]] == 0)
                        mp.erase(s[i]);
                    i++;
                    ws--; // increasing left meaning window size is shrinked.
                }
                j++;
            }
        }
        return res;
    }
};