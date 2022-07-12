class Solution
{
public:
    void solve(int idx, vector<int> &res, int sum, vector<int> &arr)
    {
        if (idx == arr.size())
        {
            res.push_back(sum);
            return;
        }
        // pick it
        solve(idx + 1, res, sum + arr[idx], arr);

        // not pick
        solve(idx + 1, res, sum, arr);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> res;
        solve(0, res, 0, arr);
        sort(res.begin(), res.end());
        return res;
    }
};