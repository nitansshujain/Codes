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
    vector<int> rightSideView(TreeNode *root)
    {
        // Approach 1 - level order
        vector<int> res;
        if (root == NULL)
            return res;
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *temp = NULL;
        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 1; i <= sz; i++)
            {
                temp = q.front();
                q.pop();

                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);

                // if(i==sz)res.push_back(temp->val); // Also correct
            }
            res.push_back(temp->val);
        }
        return res;

        // Approach 2 - Recursive traversal - preorder to be precise
        vector<int> res;
        solve(root, 0, res);
        return res;
    }

    void solve(TreeNode *root, int lvl, vector<int> &res)
    {
        if (!root)
            return;

        if (lvl == res.size())
        {
            res.push_back(root->val);
        }

        solve(root->right, lvl + 1, res);
        solve(root->left, lvl + 1, res);
    }
};