class Solution
{
public:
    string makeFancyString(string s)
    {
        // Approach 1
        // string res="";
        // int n = s.size();
        // int i;
        // for(i=1;i<s.size()-1;i++){
        //     if(s[i-1] == s[i] && s[i] == s[i+1]) continue;
        //     res += s[i-1];
        // }
        // // since last 2 chars will remain wfter loop
        // if(n >= 1) res += s[i-1]; // here i>=1
        // if(n >= 2) res += s[i];
        // return res;

        // Approach 2
        int cnt = 1;
        string res = "";
        res.push_back(s[0]);

        for (int i = 1; i < s.length(); ++i)
        {
            cnt = (s[i] == s[i - 1]) ? cnt + 1 : 1;

            if (cnt < 3)
            {
                res.push_back(s[i]);
            }
        }
        return res;
    }
};