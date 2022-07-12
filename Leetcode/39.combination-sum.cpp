class Solution
{
public:
    void solve(int idx, vector<vector<int>> &res, vector<int> &temp, vector<int> &candidates, int &target)
    {
        if (idx == candidates.size())
        {
            if (target == 0)
            {
                res.push_back(temp);
            }
            return;
        }

        // Either we can subtract the candidates[idx] from target here. But since target is referenced variable we can't subtract in by passing the subtracted value like solve(...., target-candidates[idx]). What we can do is to remove '&' from target variable and passing the subtracted value.
        if (candidates[idx] <= target)
        {
            temp.push_back(candidates[idx]);
            target -= candidates[idx];
            solve(idx, res, temp, candidates, target);
            temp.pop_back();
            target += candidates[idx];
        }

        solve(idx + 1, res, temp, candidates, target);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> temp;

        solve(0, res, temp, candidates, target);
        return res;
    }
};