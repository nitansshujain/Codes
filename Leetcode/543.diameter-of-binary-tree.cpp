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
    int diameterOfBinaryTree(TreeNode *root)
    {
        // Aprroach 1
        // int res=0;
        // solve(root,res);
        // return res-1;

        // Aprroach 2
        return solve(root).first - 1;
    }

    // (diameter, height)
    pair<int, int> solve(TreeNode *root)
    {
        if (!root)
        {
            return {0, 0};
        }

        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);

        int op1 = left.first;                     // res at left only
        int op2 = right.first;                    // res at right only
        int op3 = left.second + right.second + 1; // res at both te sides of the root

        pair<int, int> res;
        res.first = max(op1, max(op2, op3));
        res.second = max(left.second, right.second) + 1;

        return res;
    }
    //     int solve(TreeNode* root,int &res){
    //         if(!root)return 0;
    //         int lh=solve(root->left,res);
    //         int rh=solve(root->right,res);

    //         res=max(lh+rh+1,res);

    //         return 1+max(lh,rh);
    //     }
};