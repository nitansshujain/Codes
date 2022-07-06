class Solution
{
public:
    string decodeString(string s)
    {
        /*
            1. digit - add to currNum
            2. char - append to currString
            3. '[' - push currstring & currNum into stack, and reinit
            4. ']' - pop currNum & currstring from stack and do operation.
        */
        int currNum = 0, prevNum = 0;
        string currString = "", prevString = "";

        stack<string> st;

        for (auto &c : s)
        {
            if (isdigit(c))
            {
                currNum = currNum * 10 + (c - '0');
            }
            else if (c == '[')
            {
                st.push(to_string(currNum));
                st.push(currString);
                currNum = 0;
                currString = "";
            }
            else if (c == ']')
            {
                prevString = st.top();
                st.pop();
                prevNum = stoi(st.top());
                st.pop();

                // currString = prevString + prevNum*currString;
                string temp = "";
                for (int i = 0; i < prevNum; i++)
                {
                    // temp.push_back(currString); // WRONG
                    temp += currString;
                }
                currString = prevString + temp;
            }
            else
            {
                currString += c;
            }
        }

        return currString;
    }
};