class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        // O(n), O(n)
        //         stack<char>s_st;
        //         stack<char>t_st;

        //         for(auto &c:s){
        // and condition k sath !s_st.empty() nhi kr skte vrna else me '# add ho skta -> s="a##"
        //             if(c == '#'){
        //                 if(!s_st.empty()) s_st.pop();
        //             }
        //             else s_st.push(c);
        //         }

        //         for(auto &c:t){
        //             if(c == '#'){
        //                 if(!t_st.empty()) t_st.pop();
        //             }
        //             else t_st.push(c);
        //         }

        //         if(s_st.size() != t_st.size()) return false;

        //         while(!s_st.empty()){
        //             char cs = s_st.top(); s_st.pop();
        //             char ct = t_st.top(); t_st.pop();
        //             if(cs != ct) return false;
        //         }
        //         return true;

        /*
        Can you do it in O(N) time and O(1) space?
        I believe you have one difficulty here:
        When we meet a char, we are not sure if it will be still there or be deleted.

        However, we can do a back string compare (just like the title of problem).
        If we do it backward, we meet a char and we can be sure this char won't be deleted.
        If we meet a '#', it tell us we need to skip next lowercase char.

        The idea is that, read next letter from end to start.
        If we meet #, we increase the number we need to step back, until back = 0
        */
        int i = s.length() - 1, j = t.length() - 1, back;
        while (true)
        {
            back = 0;
            while (i >= 0 && (back > 0 || s[i] == '#'))
            {
                back += s[i] == '#' ? 1 : -1;
                i--;
            }
            back = 0;
            while (j >= 0 && (back > 0 || t[j] == '#'))
            {
                back += t[j] == '#' ? 1 : -1;
                j--;
            }
            // WRONG - see ex-2
            // while(i>=0 && s[i] == '#'){
            //     back++;
            //     i--;
            // }
            // while(back--) i--;
            // back = 0;
            // while(j>=0 && t[j] == '#'){
            //     back++;
            //     j--;
            // }
            // while(back--) j--;

            if (i >= 0 && j >= 0 && s[i] == t[j])
            {
                i--;
                j--;
            }
            else
            {
                break;
            }
        }
        return i == -1 && j == -1;
    }
};