class Solution
{
public:
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (nums.size() < k || (sum % k) != 0)
            return false;
        vector<bool> vis(nums.size());
        /*
        Why we need to sort the nums array in decreasing order
: The ans for this is when we sort the array so we can exclude some unneccesory calculation for nums[i]+curr_sum>target
        */
        sort(nums.begin(), nums.end(), greater<int>());
        return backtrack(0, sum / k, 0, vis, nums, k);
    }

    bool backtrack(int i, const int target, int curr_sum, vector<bool> &vis, vector<int> &nums, int k)
    {
        if (k == 1) // if k == 1 then we found all subsets
            return true;

        if (i >= nums.size())
            return false;

        if (curr_sum == target) // we found one subset, go on to the next one starting from curr_sum = 0
            return backtrack(0, target, 0, vis, nums, k - 1);

        for (int j = i; j < nums.size(); j++)
        {
            if (vis[j] || curr_sum + nums[j] > target)
                continue; // if we visited this index already or curr_sum + nums[j] > target then we can't use it

            vis[j] = true;
            if (backtrack(j + 1, target, curr_sum + nums[j], vis, nums, k))
                return true;
            vis[j] = false;
        }
        return false;
    }
};