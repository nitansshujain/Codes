#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

int main()
{
    fast;
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        stack<char> st;
        int n = s.size();
        int i = 0;
        string rpn = "";
        while (i < n)
        {
            if (isalpha(s[i]))
            {
                rpn += s[i];
            }
            else if (s[i] == ')')
            {
                while (st.top() != '(')
                {
                    rpn += st.top();
                    st.pop();
                }
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
            i++;
        }

        cout << rpn << "\n";
    }
    return 0;
}