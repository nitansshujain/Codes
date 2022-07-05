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
    bool isCompleteTree(TreeNode *root)
    {
        // level order tranversal , go from left right, if NULL node is found, then it must be the last node
        queue<TreeNode *> q;
        q.push(root);
        bool lastnode = false;
        while (!q.empty())
        {
            TreeNode *front = q.front();
            q.pop();
            if (front == NULL)
                lastnode = true;
            else
            {
                if (lastnode)
                    return false; // since we have found the last node, then it must be the last one

                // directly push into the queue withour checking the left/right node
                q.push(front->left);
                q.push(front->right);
            }
        }
        return true;
    }
};