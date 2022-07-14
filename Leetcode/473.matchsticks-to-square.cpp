class Solution
{
public:
    bool makesquare(vector<int> &matchsticks)
    {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (matchsticks.size() < 4 || (sum % 4) != 0)
            return false;
        vector<bool> vis(matchsticks.size());
        /*
        Why we need to sort the matchsticks array in decreasing order
: The ans for this is when we sort the array so we can exclude some unneccesory calculation for matchsticks[i]+curr_sum>target
        */
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        return backtrack(matchsticks, vis, sum / 4, 0, 0, 4);
    }

    bool backtrack(vector<int> &matchsticks, vector<bool> &vis, const int target, int curr_sum, int i, int k)
    {
        if (k == 1) // if k == 1 then we found all subsets
            return true;

        if (i >= matchsticks.size())
            return false;
        if (curr_sum == target) // we found one subset, go on to the next one starting from curr_sum = 0
            return backtrack(matchsticks, vis, target, 0, 0, k - 1);

        for (int j = i; j < matchsticks.size(); j++)
        {
            if (vis[j] || curr_sum + matchsticks[j] > target)
                continue; // if we visited this index already or curr_sum + matchsticks[j] > target then we can't use it

            vis[j] = true;
            if (backtrack(matchsticks, vis, target, curr_sum + matchsticks[j], j + 1, k))
                return true;
            vis[j] = false;
        }
        return false;
    }
};