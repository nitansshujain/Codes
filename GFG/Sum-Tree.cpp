// Should return true if tree is Sum Tree, else false
class Solution
{
public:
    pair<bool, int> solve(Node *root)
    {
        if (!root)
        {
            return {true, 0};
        }

        if (!root->left && !root->right)
        {
            return {true, root->data};
        }

        pair<bool, int> left = solve(root->left);
        pair<bool, int> right = solve(root->right);

        bool left_ans = left.first;
        bool right_ans = right.first;
        bool condition = (root->data == left.second + right.second);

        pair<bool, int> res;
        res.first = (left_ans && right_ans && condition);
        res.second = left.second + right.second + root->data;

        return res;
    }
    int checkTree(Node *root, bool &flag)
    {
        if (root == NULL)
        {
            return 0;
        }
        if (root->left == NULL && root->right == NULL)
        {
            return root->data;
        }
        int lsum = checkTree(root->left, flag);
        int rsum = checkTree(root->right, flag);
        int sum = lsum + rsum;
        if (root->data != sum)
        {
            flag = false;
        }
        return sum + (root->data);
    }
    bool isSumTree(Node *root)
    {
        // Approach 1 - Simple DFS
        return solve(root).first;

        // Approach 2 - CodeHelp
        bool flag = true;
        checkTree(root, flag);
        return flag;
    }
};