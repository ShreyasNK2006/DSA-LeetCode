/*
 * Problem 0032: Longest Valid Parentheses
 * URL     : https://leetcode.com/problems/longest-valid-parentheses/
 * Solved  : 2026-04-20
 * Runtime : 0 ms
 * Memory  : 11.8 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int len=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            st.push(i);
            else
            {
                st.pop();
                if(st.empty())
                st.push(i);
                else
                len=max(len,i-st.top());
            }
        }
        return len;
    }
};