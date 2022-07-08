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
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        // This is premium problem where maintinating level is not important.
        vector<int> res;
        map<int, vector<int>> m;        // (hor-dis, vector)
        queue<pair<TreeNode *, int>> q; // (TreeNode, hor-dis)
        q.push({root, 0});

        while (!q.empty())
        {
            auto front = q.front();
            q.pop();

            TreeNode *node = front.first;
            int dis = front.second;
            m[dis].push_back(node->data);

            if (node->left)
            {
                q.push({node->left, dis - 1});
            }
            if (node->right)
            {
                q.push({node->right, dis + 1});
            }
        }

        for (auto it : m)
        {
            vector<int> v = it.second;
            for (auto &x : v)
            {
                res.push_back(x);
            }
        }
        return res;
    }
};