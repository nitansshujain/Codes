/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int pathSum(TreeNode *root, int k)
    {
        // Approach 1 - O(N*2), O(N)
        // int res_cnt=0;
        // vector<int>path;
        // solve1(root,k,path,res_cnt);
        // return res_cnt;

        // Approach 2 - O(N), O(N) - Optimised, using map
        unordered_map<long long int, long long int> mp;
        mp[0] = 1; // IMPORTANT

        int res_cnt = 0;

        solve2(root, mp, k, res_cnt, 0);

        return res_cnt;
    }

    void solve1(TreeNode *root, int k, vector<int> &path, int &res_cnt)
    {
        if (!root)
        {
            return;
        }
        path.push_back(root->val);

        solve1(root->left, k, path, res_cnt);
        solve1(root->right, k, path, res_cnt);

        long long int curr_sum = 0;
        for (int i = path.size() - 1; i >= 0; i--)
        {
            curr_sum += path[i];
            if (curr_sum == k)
                res_cnt++;
        }

        path.pop_back();
    }

    void solve2(TreeNode *root, unordered_map<long long int, long long int> &mp, int k, int &res_cnt, long long int curr_sum)
    {
        if (!root)
            return;

        curr_sum += root->val;
        if (mp.find(curr_sum - k) != mp.end())
            res_cnt += mp[curr_sum - k]; // IMPORTANT

        mp[curr_sum]++;

        solve2(root->left, mp, k, res_cnt, curr_sum);
        solve2(root->right, mp, k, res_cnt, curr_sum);

        mp[curr_sum]--;
    }
};