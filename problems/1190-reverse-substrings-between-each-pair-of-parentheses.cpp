/*
 * Problem 1190: Reverse Substrings Between Each Pair of Parentheses
 * URL     : https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
 * Solved  : 2026-09-27
 * Runtime : 0 ms
 * Memory  : 11.5 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        stack<string> st;
        int open =0;
        string res;
        for(int i=0;i<n;i++)
        {
            string x;
            x+=s[i];
            if(s[i]=='(')
            open++;
            if(open==0)
            {
                res+=s[i];
                continue;
            }
            if(s[i]!=')')
            st.push(x);
            else
            {
                open--;
                string temp;
                while(st.top()!="(")
                {
                    string y = st.top();
                    reverse(y.begin(),y.end());
                    temp+=y;
                    st.pop();
                }
                st.pop();
                if(st.empty())
                {
                    res+=temp;
                    continue;
                }
                st.push(temp);
            }
        }
        
        while(!st.empty())
        {
            res+=st.top();
            st.pop();
        }
        //reverse(res.begin(),res.end());
        return res;

    }
};