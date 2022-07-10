class Solution
{
public:
    Node *mapping_and_target(Node *root, int target, unordered_map<Node *, Node *> &mp)
    {
        Node *target_node = NULL;
        queue<Node *> q;
        q.push(root);
        mp[root] = NULL;

        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();

            if (curr->data == target)
                target_node = curr;

            if (curr->left)
            {
                mp[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right)
            {
                mp[curr->right] = curr;
                q.push(curr->right);
            }
        }

        return target_node;
    }

    int burn_tree(Node *target_node, unordered_map<Node *, Node *> &mp)
    {
        int burning_time = 0;
        unordered_map<Node *, bool> vis;
        queue<Node *> q;
        q.push(target_node);
        vis[target_node] = true;

        while (!q.empty())
        {
            int sz = q.size();
            bool inserted_in_q = false;
            for (int i = 0; i < sz; i++)
            {
                Node *curr = q.front();
                q.pop();

                if (curr->left && !vis[curr->left])
                {
                    vis[curr->left] = true;
                    q.push(curr->left);
                    inserted_in_q = true;
                }
                if (curr->right && !vis[curr->right])
                {
                    vis[curr->right] = true;
                    q.push(curr->right);
                    inserted_in_q = true;
                }
                if (mp[curr] && !vis[mp[curr]])
                {
                    vis[mp[curr]] = true;
                    q.push(mp[curr]);
                    inserted_in_q = true;
                }
            }

            if (inserted_in_q)
                burning_time++;
        }

        return burning_time;
    }
    int minTime(Node *root, int target)
    {
        // Algorithm:
        // 1.(a) Create mapping Node_to_parent.
        // 1.(b) Find target node
        // 2. Burn the tree

        unordered_map<Node *, Node *> mp;
        Node *target_node = mapping_and_target(root, target, mp);

        int ans = burn_tree(target_node, mp);

        return ans;
    }
};