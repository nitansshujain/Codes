/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

// Function to return a tree created from postorder and inoreder traversals.
Node *build(int in[], int post[], int &post_order_idx, unordered_map<int, int> &mp, int n, int s, int e)
{ // s,e ->inorder array
    if (post_order_idx < 0 || s > e)
        return NULL;

    int pos = mp[post[post_order_idx--]];

    Node *root = new Node(in[pos]);

    // first elements are inserted in right, then left
    root->right = build(in, post, post_order_idx, mp, n, pos + 1, e);
    root->left = build(in, post, post_order_idx, mp, n, s, pos - 1);

    return root;
}

Node *buildTree(int in[], int post[], int n)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[in[i]] = i;
    }
    int post_order_idx = n - 1;

    return build(in, post, post_order_idx, mp, n, 0, n - 1);
}