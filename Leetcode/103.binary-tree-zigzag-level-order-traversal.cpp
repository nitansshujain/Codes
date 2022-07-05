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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (!root)
            return res;

        queue<TreeNode *> q;
        q.push(root);

        bool left_to_right = true;

        while (!q.empty())
        {
            int sz = q.size();
            vector<int> temp(sz);

            for (int i = 0; i < sz; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                int idx = left_to_right ? i : sz - i - 1;
                temp[idx] = curr->val;

                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }

            left_to_right = !left_to_right;

            // for(auto x:temp){
            //     res.push_back(x);
            // }
            res.push_back(temp);
        }
        return res;
    }
};