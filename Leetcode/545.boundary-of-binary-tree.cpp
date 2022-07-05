class Solution
{
public:
    void printLeft(Node *root, vector<int> &res)
    {
        if (!root || (!root->left && !root->right))
            return;

        res.push_back(root->data);

        if (root->left)
            printLeft(root->left, res);
        else
            printLeft(root->right, res); // else case is important here
    }
    void printLeaf(Node *root, vector<int> &res)
    {
        if (!root)
            return;

        if (!root->left && !root->right)
        {
            res.push_back(root->data);
            return;
        }

        printLeaf(root->left, res);
        printLeaf(root->right, res);
    }
    void printRight(Node *root, vector<int> &res)
    {
        if (!root || (!root->left && !root->right))
            return;

        if (root->right)
            printRight(root->right, res);
        else
            printRight(root->left, res);

        res.push_back(root->data);
    }
    vector<int> boundary(Node *root)
    {
        vector<int> res;
        if (!root)
            return res;

        res.push_back(root->data);
        if (!root->left && !root->right)
            return res;

        printLeft(root->left, res);
        printLeaf(root, res);
        printRight(root->right, res);

        return res;
    }
};