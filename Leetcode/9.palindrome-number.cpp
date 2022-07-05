class Solution
{
public:
    bool isPalindrome(int x)
    {
        // Approach 1
        // string s=to_string(x);
        // if(s[0]=='-'){
        //     return 0;
        // }
        // string s1=s;
        // reverse(s1.begin(),s1.end());
        // for(int i=0;i<s.length();i++){
        //     if(s[i]!=s1[i]){
        //         return false;
        //     }
        // }
        // return true;

        // Approach 2
        if (x < 0)
            return false;
        int rx = 0;
        int temp = x;
        while (temp)
        {
            int rem = temp % 10;
            if ((rx > INT_MAX / 10) || (rx == INT_MAX / 10 && rem > INT_MAX % 10))
                return false;
            rx = rx * 10 + rem;
            temp /= 10;
        }
        // cout<<x<<" "<<rx<<endl;
        // while(x){
        //     int rem_x = x%10;
        //     int rem_rx = rx%10;
        //     if(rem_x != rem_rx) return false;
        //     x /= 10;
        //     rx/=10;
        // }
        // return true;
        return x == rx;
    }
};