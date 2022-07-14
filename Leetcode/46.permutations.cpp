class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        // Approach 1 - we can use vis vector or bitmasking of bits as a vis vector
        // vector<vector<int>>res;
        // vector<int>temp;
        // // int mask=(1<<n)-1;
        // vector<bool>vis(n,false);
        // // solve(res,temp,nums,mask);
        // solve(res,temp,nums,vis);
        // return res;

        // Approach 2 - using swap

        vector<vector<int>> res;
        recurPermute(0, nums, res);
        int n = nums.size();
        return res;
    }
    /*
    [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,2,1],[3,1,2]]
    [[0,1],[1,0]]
    [[1]]
    */
    void recurPermute(int index, vector<int> &nums, vector<vector<int>> &res)
    {
        if (index == nums.size())
        {
            res.push_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); i++)
        {
            swap(nums[index], nums[i]);
            recurPermute(i + 1, nums, res);
            swap(nums[index], nums[i]);
        }
    }
    void solve(vector<vector<int>> &res, vector<int> &temp, vector<int> &nums, vector<bool> vis)
    {
        // if(mask==0 && temp.size()!=0){// temp.size()==0 is not necessary
        if (temp.size() == nums.size())
        {
            res.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            // if(mask&(1<<i))
            if (!vis[i])
            {
                temp.push_back(nums[i]);
                vis[i] = true;
                // solve(res,temp,nums,mask^(1<<i));
                solve(res, temp, nums, vis);
                temp.pop_back();
                vis[i] = false;
            }
        }
        return;
    }
};