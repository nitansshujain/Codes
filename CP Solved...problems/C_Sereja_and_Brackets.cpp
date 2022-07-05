#include <bits/stdc++.h>
using namespace std;
struct info
{
    int open, close, full;
    info(int _open, int _close, int _full)
    {
        open = _open;
        close = _close;
        full = _full;
    }
    info()
    {
        open = 0;
        close = 0;
        full = 0;
    }
};
class STree
{
public:
    vector<info> seg;

    STree(int n)
    {
        seg.resize(4 * n + 1);
    }

    info merge(info left, info right)
    {
        info res = info(0, 0, 0);
        res.full = left.full + right.full + min(left.open, right.close);
        res.open = left.open + right.open - min(left.open, right.close);
        res.close = left.close + right.close - min(left.open, right.close);
        return res;
    }
    void build(int idx, int low, int high, string &s)
    {
        if (low == high)
        {
            seg[idx] = info(s[low] == '(', s[low] == ')', 0);
            return;
        }

        int mid = low + (high - low) / 2;
        build(2 * idx + 1, low, mid, s);
        build(2 * idx + 2, mid + 1, high, s);
        seg[idx] = merge(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    info query(int idx, int low, int high, string &s, int l, int r)
    {
        // no overlap
        // l r low high or low high l r
        if (r < low || high < l)
            return info(0, 0, 0);

        // complete overlap
        // [l low high r]
        if (l <= low && r >= high)
            return seg[idx];
        int mid = low + (high - low) / 2;
        info left = query(2 * idx + 1, low, mid, s, l, r);
        info right = query(2 * idx + 2, mid + 1, high, s, l, r);

        return merge(left, right);
    }
};

int main()
{
    string s;
    cin >> s;

    int n = s.size();
    STree STree(4 * n);

    STree.build(0, 0, n - 1, s);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;

        info res = STree.query(0, 0, n - 1, s, l, r);
        cout << res.full * 2 << endl;
    }
}