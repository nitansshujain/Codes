class Solution
{
public:
    // Function to return the maximum sum of non-adjacent nodes.

    pair<int, int> solve(Node *root)
    {
        if (!root)
        {
            return {0, 0};
        }

        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);

        pair<int, int> res;
        res.first = root->data + left.second + right.second;
        res.second = max(left.first, left.second) + max(right.first, right.second);

        return res;
    }
    int getMaxSum(Node *root)
    {
        // first -> include; second->exclude
        pair<int, int> res = solve(root);

        return max(res.first, res.second);
    }
};