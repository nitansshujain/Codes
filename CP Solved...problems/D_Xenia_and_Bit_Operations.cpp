#include <bits/stdc++.h>
using namespace std;
class STree
{
public:
    vector<int> seg;

    STree(int n)
    {
        seg.resize(4 * n + 1);
    }

    void build(int idx, int low, int high, int arr[], int orr)
    {
        if (low == high)
        {
            seg[idx] = arr[low];
            return;
        }

        int mid = low + (high - low) / 2;
        build(2 * idx + 1, low, mid, arr, !orr);
        build(2 * idx + 2, mid + 1, high, arr, !orr);
        if (orr)
            seg[idx] = seg[2 * idx + 1] | seg[2 * idx + 2];
        else
            seg[idx] = seg[2 * idx + 1] ^ seg[2 * idx + 2];
    }

    void update(int idx, int low, int high, int i, int val, int orr)
    {
        if (low == high)
        {
            seg[idx] = val;
            return;
        }

        int mid = low + (high - low) / 2;
        if (i <= mid)
            update(2 * idx + 1, low, mid, i, val, !orr);
        else
            update(2 * idx + 2, mid + 1, high, i, val, !orr);
        if (orr)
            seg[idx] = seg[2 * idx + 1] | seg[2 * idx + 2];
        else
            seg[idx] = seg[2 * idx + 1] ^ seg[2 * idx + 2];
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    int elem = pow(2, n);
    int arr[elem];

    for (int i = 0; i < elem; i++)
    {
        cin >> arr[i];
    }
    STree STree(4 * elem);

    if (n & 1)
        STree.build(0, 0, elem - 1, arr, 1);
    else
        STree.build(0, 0, elem - 1, arr, 0);
    while (m--)
    {
        int i, val;
        cin >> i >> val;
        i--;

        if (n & 1)
            STree.update(0, 0, elem - 1, i, val, 1);
        else
            STree.update(0, 0, elem - 1, i, val, 0);
        cout << STree.seg[0] << endl;
    }
    return 0;
}
