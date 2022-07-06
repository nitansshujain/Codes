/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
    vector<int> preorder(Node *root)
    {
        vector<int> res;
        if (!root)
            return res;
        // Approach 1
        // solve(res,root);

        // Approach 2
        stack<Node *> st;
        st.push(root);
        while (!st.empty())
        {
            Node *node = st.top();
            st.pop();
            res.push_back(node->val);
            for (int i = node->children.size() - 1; i >= 0; i--)
            {
                if (node->children[i] != NULL)
                {
                    st.push(node->children[i]);
                }
            }
        }
        return res;
    }

    void solve(vector<int> &res, Node *root)
    {
        if (!root)
            return;
        res.push_back(root->val);

        for (Node *x : root->children)
        {
            solve(res, x);
        }
    }
};