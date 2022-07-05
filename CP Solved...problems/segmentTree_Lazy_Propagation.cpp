#include <bits/stdc++.h>
using namespace std;
class STree
{
public:
    vector<int> seg, lazy;
    STree(int n)
    {
        seg.resize(4 * n);
        lazy.resize(4 * n);
    }
    void build(int idx, int low, int high, int arr[])
    {
        if (low == high)
        {
            seg[idx] = arr[low];
            return;
        }

        int mid = low + (high - low) / 2;
        build(2 * idx + 1, low, mid, arr);
        build(2 * idx + 2, mid + 1, high, arr);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2]; // For min use min
    }
    void update(int idx, int low, int high, int l, int r, int val)
    {
        // update the previous remaining updates
        // and propogate downwards
        if (lazy[idx] != 0)
        {
            seg[idx] += (high - low + 1) * lazy[idx]; // For min  => seg[idx] += lazy[idx];
            // propogate the lazy update downwards
            // for the remaining nodes to get updated
            if (low != high)
            {
                lazy[2 * idx + 1] += lazy[idx];
                lazy[2 * idx + 2] += lazy[idx];
            }

            lazy[idx] = 0;
        }
        // no overlap
        // we don't do anything and return
        // low high l r or l r low high
        if (high < l or r < low)
        {
            return;
        }

        // complete overlap
        // l low high r
        if (l <= low && r >= high)
        {
            seg[idx] += (high - low + 1) * val; // For min => seg[idx] += val;
            // if a leaf node, it will have childrens
            if (low != high)
            {
                lazy[2 * idx + 1] += val;
                lazy[2 * idx + 2] += val;
            }
            return;
        }

        // last case has to be partial overlap case
        int mid = low + (high - low) / 2;
        update(2 * idx + 1, low, mid, l, r, val);
        update(2 * idx + 2, mid + 1, high, l, r, val);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2]; // For min use min
    }

    int query(int idx, int low, int high, int l, int r)
    {
        if (lazy[idx] != 0)
        {
            seg[idx] += (high - low + 1) * lazy[idx]; // For min  => seg[idx] += lazy[idx];
            if (low != high)
            {
                lazy[2 * idx + 1] += lazy[idx];
                lazy[2 * idx + 2] += lazy[idx];
            }
            lazy[idx] = 0;
        }
        // no overlap return 0;
        if (high < l || r < low)
            return 0; // For min  => return INT_MAX;

        // complete overlap
        if (l <= low && r >= high)
            return seg[idx];

        int mid = low + (high - low) / 2;

        int left = query(2 * idx + 1, low, mid, l, r);
        int right = query(2 * idx + 2, mid + 1, high, l, r);
        return left + right; // For min use min
    }
};
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    STree stree(n);
    stree.build(0, 0, n - 1, arr);

    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l, r;
            cin >> l >> r;
            cout << stree.query(0, 0, n - 1, l, r) << endl;
        }
        else
        {
            int l, r, val;
            cin >> l >> r >> val;
            stree.update(0, 0, n - 1, l, r, val);
        }
    }
    return 0;
}
// 5
// 1 2 3 4 5
// 3
// 1 0 4
// 2 1 3 2
// 1 0 4

// https://ideone.com/gvipU8