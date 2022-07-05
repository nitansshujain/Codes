class Solution
{
public:
    int reverse(int x)
    {
        // Ignoring the last digit, and check for all other digits, if satisfied then only push into res.
        int res = 0;
        while (x)
        {
            int rem = x % 10;
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && rem > INT_MAX % 10))
                return 0;
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && rem < INT_MIN % 10))
                return 0;
            res = (res * 10) + rem;
            x /= 10;
        }
        return res;
    }
};