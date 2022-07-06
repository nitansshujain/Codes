// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        // vector<int>v;
        // for(int i=0;i<n;i++){
        //     v[i]=i+1;
        // }
        int l = 1, r = n;
        // int mn=INT_MAX;
        int res = -1; // candidate search krna h, 1...mid..bad...n -> candidate ko store aur left me jana h.
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (isBadVersion(mid) == true)
            {
                // mn=min(mn,mid);
                res = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return res;
    }
};