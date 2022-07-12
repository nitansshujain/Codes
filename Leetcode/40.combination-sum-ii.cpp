class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> temp;

        // TLE
        // set<vector<int>>seta; // unordered_set does not contain containers, we have to use set, which sorts the items
        // solve1(seta,temp,candidates,target,0);
        // for(auto s:seta){
        //     res.push_back(s);
        // }

        // Approach 2a - using pick, not pick, tree in depth
        // solve2a(res,temp,candidates,target,0);

        // Approach 2b - using sequences, tree in width
        solve2b(res, temp, candidates, target, 0);
        return res;
    }

    void solve1(set<vector<int>> &seta, vector<int> &temp, vector<int> &candidates, int &target, int idx)
    {
        if (target == 0)
        {
            // sort(temp.begin(),temp.end());
            seta.insert(temp);
            return;
        }
        if (idx == candidates.size())
            return;

        if (candidates[idx] <= target)
        {
            temp.push_back(candidates[idx]);
            target -= candidates[idx];

            solve1(seta, temp, candidates, target, idx + 1);

            target += candidates[idx];
            temp.pop_back();
        }

        solve1(seta, temp, candidates, target, idx + 1);
    }

    void solve2a(vector<vector<int>> &res, vector<int> &temp, vector<int> &candidates, int &target, int idx)
    {
        if (target == 0)
        {
            res.push_back(temp);
            return;
        }
        if (idx == candidates.size() || candidates[idx] > target)
            return;

        int num = candidates[idx++];
        temp.push_back(num);
        target -= num;
        solve2a(res, temp, candidates, target, idx); // can do (target-num) here only

        target += num;
        temp.pop_back();

        while (idx < candidates.size() && candidates[idx] == num)
            idx++;

        solve2a(res, temp, candidates, target, idx);
    }

    void solve2b(vector<vector<int>> &res, vector<int> &temp, vector<int> &candidates, int target, int idx)
    {
        if (target == 0)
        {
            res.push_back(temp);
            return;
        }
        for (int i = idx; i < candidates.size(); i++)
        {
            if (i > idx && candidates[i] == candidates[i - 1])
                continue;
            if (candidates[i] > target)
                return;
            temp.push_back(candidates[i]);
            solve2b(res, temp, candidates, target - candidates[i], i + 1);
            temp.pop_back();
        }
    }
};