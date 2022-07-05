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
    int sum = 0;
    // finding inorder successor
    TreeNode *inSucc(TreeNode *root)
    {
        TreeNode *temp = root->right;
        while (temp->left != NULL and temp->left != root)
        {
            temp = temp->left;
        }
        return temp;
    }
    TreeNode *rev_morris(TreeNode *root)
    {
        TreeNode *root1 = root;
        while (root1 != NULL)
        {
            if (root1->right == NULL)
            {
                sum += root1->val;
                root1->val = sum;
                root1 = root1->left;
            }
            else
            {
                TreeNode *succ = inSucc(root1);
                // if not visited
                if (succ->left == NULL)
                {
                    succ->left = root1;
                    root1 = root1->right;
                }
                // next visit - so move left
                else
                {
                    succ->left = NULL;
                    sum += root1->val;
                    root1->val = sum;
                    root1 = root1->left;
                }
            }
        }
        return root;
    }

    TreeNode *bstToGst(TreeNode *root)
    {
        // Approach 1 - dfs O(n) , O(n)
        solve(root);
        return root;

        // Approach 2- Iterative DFS o(n), O(n)
        stack<TreeNode *> st;
        TreeNode *node = root;
        while (!st.empty() || node != NULL)
        {
            while (node)
            {
                st.push(node);
                node = node->right;
            }
            node = st.top();
            st.pop(); // Use the same node, don't create new node major for iterative dfs
            sum += node->val;
            node->val = sum;

            node = node->left;
        }
        return root;

        // Approach 3- Reverse Morris Traversal O(n), O(1)
        if (!root)
            return root;
        return rev_morris(root);
    }

    void solve(TreeNode *root)
    {
        if (!root)
            return;

        solve(root->right);

        root->val += sum;
        sum = root->val;
        // root->val = (sum+=root->val); // Also true

        solve(root->left);
    }
};