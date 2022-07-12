class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        // https://leetcode.com/problems/subsets/discuss/27278/C%2B%2B-RecursiveIterativeBit-Manipulation
        // Approach 1 - Recursion
        vector<vector<int>> res;
        vector<int> ds;
        solve(0, res, ds, nums);
        // sort(res.begin(),res.end()); No need as stated in the problem
        return res;

        // Approach 2 - Iterative
        vector<vector<int>> subs = {{}};
        for (int num : nums)
        {
            int n = subs.size();
            for (int i = 0; i < n; i++)
            {
                subs.push_back(subs[i]);
                subs.back().push_back(num);
            }
        }
        return subs;

        // Approach 3 - Bit Manipulation
        int n = nums.size(), p = 1 << n;
        vector<vector<int>> subs(p);
        for (int i = 0; i < p; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((i >> j) & 1)
                {
                    subs[i].push_back(nums[j]);
                }
            }
        }
        return subs;
    }

    void solve(int idx, vector<vector<int>> &res, vector<int> &ds, vector<int> &nums)
    {
        if (idx == nums.size())
        {
            res.push_back(ds);
            return;
        }
        // pick it
        ds.push_back(nums[idx]);
        solve(idx + 1, res, ds, nums);

        ds.pop_back();

        // not pick
        solve(idx + 1, res, ds, nums);
    }
};