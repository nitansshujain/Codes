class TreeAncestor
{
public:
    /*
    Hints
https://leetcode.com/problems/kth-ancestor-of-a-tree-node/discuss/686268/Explanation-with-c%2B%2B-sample-code
https://www.youtube.com/watch?v=PE-kQVZxvWA&list=PL-Jc9J83PIiGC6uQ2CjMhSaWAcmjbAQfp&index=1&ab_channel=Pepcoding
    */

    vector<vector<int>> P; // P[i][node] :::: [node] 's [2^i]th parent
    TreeAncestor(int n, vector<int> &parent)
    {
        // initialize
        P.resize(17, vector<int>(parent.size(), -1));

        // 2^0
        for (int i = 0; i < n; i++)
        {
            P[0][i] = parent[i];
        }

        // 2^i
        for (int i = 1; i < 17; i++)
        {
            for (int node = 0; node < n; node++)
            {
                int nodep = P[i - 1][node];
                if (nodep != -1)
                    P[i][node] = P[i - 1][nodep];
            }
        }
    }

    int getKthAncestor(int node, int k)
    {
        for (int i = 0; i < 17; i++)
        {
            if (k & (1 << i))
            {
                node = P[i][node];
                if (node == -1)
                    return -1;
            }
        }

        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */