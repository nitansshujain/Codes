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
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> res;
        vector<int> temp;
        // solve(root, targetSum, 0,res, temp); // wrong
        solve(root, targetSum, res, temp);
        return res;
    }

    void solve(TreeNode *root, int targetSum, vector<vector<int>> &res, vector<int> &temp)
    {
        if (!root)
            return;

        temp.push_back(root->val);
        if (!root->left && !root->right && targetSum == root->val)
            res.push_back(temp);
        solve(root->left, targetSum - root->val, res, temp);
        solve(root->right, targetSum - root->val, res, temp);
        temp.pop_back();
    }

    // Wrong
    // void solve(TreeNode* root, int targetSum, int currSum, vector<vector<int>> &res, vector<int>&temp){
    //     if(!root){
    //         if(currSum == targetSum){
    //             res.push_back(temp);
    //             // temp.pop_back();
    //         }
    //         return;
    //     }
    //     temp.push_back(root->val);
    //     solve(root->left, targetSum, currSum + root->val, res, temp);
    //     solve(root->right,targetSum, currSum + root->val, res, temp);
    //     temp.pop_back();
    // }
};