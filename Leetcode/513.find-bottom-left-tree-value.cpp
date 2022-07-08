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
    int findBottomLeftValue(TreeNode *root)
    {
        // Approach 1 - dfs
        int res = 0, maxDepth = -1;
        dfs(root, 0, maxDepth, res);
        return res;

        // Approach 2 - BFS
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            root = q.front();
            q.pop();
            if (root->right)
            { // we have to push right first then left, to get the bottom leftmost val
                q.push(root->right);
            }
            if (root->left)
                q.push(root->left);
        }
        return root->val;
    }

    void dfs(TreeNode *root, int curDepth, int &maxDepth, int &res)
    {
        if (!root)
            return;

        // We can put this calculation part either here or at the end meads after both traversal
        if (curDepth > maxDepth)
        {
            res = root->val;
            maxDepth = curDepth;
        }

        dfs(root->left, curDepth + 1, maxDepth, res);
        dfs(root->right, curDepth + 1, maxDepth, res);
    }
};