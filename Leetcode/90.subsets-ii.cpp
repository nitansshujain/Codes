class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> ds;

        // Approach 1 - using set - sorting is not needed in this approach
        // set < vector < int >> seta;
        // solve1(nums, 0, ds, seta);
        // for (auto it = seta.begin(); it != seta.end(); it++) {
        //   res.push_back( *it);
        // }
        // return res;

        // Approach 2a - recursive - depth wise, pick not pick
        // solve2a(0,nums,res,ds);

        // Approach 2b - recursive - width wise
        solve2b(0, nums, res, ds);

        return res;
    }

    void solve1(vector<int> &nums, int index, vector<int> &ds, set<vector<int>> &seta)
    {
        if (index == nums.size())
        {
            sort(ds.begin(), ds.end());
            seta.insert(ds);
            return;
        }
        ds.push_back(nums[index]);
        solve1(nums, index + 1, ds, seta);
        ds.pop_back();
        solve1(nums, index + 1, ds, seta);
    }

    void solve2a(int idx, vector<int> &nums, vector<vector<int>> &res, vector<int> &ds)
    {
        if (idx == nums.size())
        {
            res.push_back(ds);
            return;
        }

        int num = nums[idx++];
        ds.push_back(num);

        solve2a(idx, nums, res, ds);
        ds.pop_back();

        while (idx < nums.size() && nums[idx] == num)
            idx++;
        solve2a(idx, nums, res, ds);
    }

    void solve2b(int idx, vector<int> &nums, vector<vector<int>> &res, vector<int> &ds)
    {
        res.push_back(ds); // direCtly push the ds

        for (int i = idx; i < nums.size(); i++)
        {
            if (i != idx && nums[i] == nums[i - 1])
                continue;
            ds.push_back(nums[i]);
            solve2b(i + 1, nums, res, ds);
            ds.pop_back();
        }
    }
};