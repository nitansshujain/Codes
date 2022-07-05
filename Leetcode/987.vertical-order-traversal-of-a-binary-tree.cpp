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
        // Similar problem is on GFG, there maintaining level explicitly is not important, it is auto taken care of
        // But here it is imp, since each level is sort in asc order.

        vector<vector<int>> res;
        if (!root)
            return res;
        map<int, map<int, multiset<int>>> mp;      // hori-Dist, (level, vector)
        queue<pair<TreeNode *, pair<int, int>>> q; // node, (hori-Dist, Level)

        q.push(make_pair(root, make_pair(0, 0)));

        while (!q.empty())
        {
            pair<TreeNode *, pair<int, int>> temp = q.front();
            q.pop();

            TreeNode *curr = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;

            mp[hd][lvl].insert(curr->val);

            if (curr->left)
                q.push(make_pair(curr->left, make_pair(hd - 1, lvl + 1)));
            if (curr->right)
                q.push(make_pair(curr->right, make_pair(hd + 1, lvl + 1)));
        }

        for (auto &x : mp)
        {
            vector<int> col;
            for (auto &y : x.second)
            {
                col.insert(col.end(), y.second.begin(), y.second.end());
            }
            res.push_back(col);
        }

        return res;
    }
};