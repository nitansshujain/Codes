class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int min_so_far = INT_MAX;
        int mx_pro = 0;
        for (auto p : prices)
        {
            min_so_far = min(min_so_far, p);
            mx_pro = max(mx_pro, p - min_so_far);
        }
        return mx_pro;
    }
};