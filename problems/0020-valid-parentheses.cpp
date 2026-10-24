/*
 * Problem 0020: Valid Parentheses
 * URL     : https://leetcode.com/problems/valid-parentheses/
 * Solved  : 2026-10-01
 * Runtime : 0 ms
 * Memory  : 8.8 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

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