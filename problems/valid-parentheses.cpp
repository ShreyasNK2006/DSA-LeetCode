# Valid Parentheses
Solved on 2025-10-18

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
            {
                st.push(s[i]);
                continue;
            }
            if(st.empty())
            return false;
            char temp= s[i];
            if(st.top()==(temp-1)|| st.top()==(temp-2))
            st.pop();
            else
            return false;
        }
    if(st.empty())
    return true;
    else 
    return false;
    }
};