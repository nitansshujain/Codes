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
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        return solve(root, targetSum, 0);
    }
    bool solve(TreeNode *root, int targetSum, int currSum)
    {
        // See Example 3, if there is no root(tree is empty)-> return targetSum==0 is incorrect
        if (!root)
            return false;

        currSum += root->val;

        if (root->left == NULL and root->right == NULL)
            return currSum == targetSum;

        return solve(root->left, targetSum, currSum) || solve(root->right, targetSum, currSum);
    }
};