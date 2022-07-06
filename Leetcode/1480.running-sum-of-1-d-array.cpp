class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        //         vector<int>res;

        //         int runningSum = nums[0];
        //         res.push_back(runningSum);
        //         for(int i=1;i<nums.size();i++){
        //             runningSum+=nums[i];
        //             res.push_back(runningSum);
        //         }
        //         return res;

        // In place
        for (int i = 1; i < nums.size(); i++)
        {
            nums[i] += nums[i - 1];
        }
        return nums;
    }
};