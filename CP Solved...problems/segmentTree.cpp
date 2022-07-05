#include <bits/stdc++.h>
using namespace std;
class STree
{
    vector<int> seg;

public:
    STree(int n)
    {
        seg.resize(4 * n + 1);
    }

    void build(int idx, int low, int high, int arr[])
    {
        if (low == high)
        {
            seg[idx] = arr[low];
            return;
        }

        int mid = (low + high) / 2;
        build(2 * idx + 1, low, mid, arr);
        build(2 * idx + 2, mid + 1, high, arr);
        seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    int query(int idx, int low, int high, int l, int r)
    {
        // no overlap
        // l r low high or low high l r
        if (r < low || high < l)
            return INT_MAX;

        // complete overlap
        // [l low high r]
        if (low >= l && high <= r)
            return seg[idx];

        int mid = (low + high) >> 1;
        int left = query(2 * idx + 1, low, mid, l, r);
        int right = query(2 * idx + 2, mid + 1, high, l, r);
        return min(left, right);
    }
    void update(int idx, int low, int high, int i, int val)
    {
        if (low == high)
        {
            seg[idx] = val;
            return;
        }

        int mid = (low + high) >> 1;
        if (i <= mid)
            update(2 * idx + 1, low, mid, i, val);
        else
            update(2 * idx + 2, mid + 1, high, i, val);
        seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
    }
};

int main()
{
    int n1;
    cin >> n1;
    int arr1[n1];
    for (int i = 0; i < n1; i++)
        cin >> arr1[i];
    STree seg1(n1);
    seg1.build(0, 0, n1 - 1, arr1);

    int n2;
    cin >> n2;
    int arr2[n2];
    for (int i = 0; i < n2; i++)
        cin >> arr2[i];
    STree seg2(n2);
    seg2.build(0, 0, n2 - 1, arr2);

    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int l1, r1, l2, r2;
            cin >> l1 >> r1 >> l2 >> r2;

            int min1 = seg1.query(0, 0, n1 - 1, l1, r1);
            int min2 = seg2.query(0, 0, n2 - 1, l2, r2);
            cout << min(min1, min2) << endl
                 << endl;
        }
        else if (type == 2)
        {
            int arrNum, i, val;
            cin >> arrNum >> i >> val;

            if (arrNum == 1)
            {
                seg1.update(0, 0, n1 - 1, i, val);
            }
            else
            {
                seg2.update(0, 0, n2 - 1, i, val);
            }
        }
    }

    return 0;
}

// https://ideone.com/mLwRjf
// 7
// 1 2 0 3 4 1 2
// 5
// 3 12 2 10 3
// 3
// 1 0 3 1 4
// 2 1 2 12
// 1 0 3 1 4