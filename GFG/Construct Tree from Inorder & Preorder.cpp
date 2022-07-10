/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution
{
public:
    // int find_position(int in[], int element, int n){
    //     for(int i=0;i<n;i++){
    //         if(in[i]==element) return i;
    //     }

    //     return -1;
    // }
    Node *solve(int in[], int pre[], unordered_map<int, int> &mp, int &pre_order_idx, int n, int s, int e)
    {
        if (pre_order_idx >= n || s > e)
        {
            return NULL;
        }

        int element = pre[pre_order_idx++];
        int pos = mp[element];

        Node *root = new Node(element);

        // first elements are inserted in left, then right
        root->left = solve(in, pre, mp, pre_order_idx, n, s, pos - 1);
        root->right = solve(in, pre, mp, pre_order_idx, n, pos + 1, e);
    }
    Node *buildTree(int in[], int pre[], int n)
    {
        int pre_order_idx = 0;

        unordered_map<int, int> mp; // mapping node->index
        for (int i = 0; i < n; i++)
        {
            mp[in[i]] = i;
        }
        Node *res = solve(in, pre, mp, pre_order_idx, n, 0, n - 1);
        // Node* res = solve(in, pre, pre_order_idx, n, 0, n-1);
        return res;
    }
};