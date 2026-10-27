/*
 * Problem 1021: Remove Outermost Parentheses
 * URL     : https://leetcode.com/problems/remove-outermost-parentheses/
 * Solved  : 2026-10-08
 * Runtime : 0 ms
 * Memory  : 8.8 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int count =0;
        int low =0;
        while(low<s.length())
        {
            if(s[low]=='(')
            {
                if(count>=1)
                res.push_back(s[low]);
                count++; 
                low++;    
            }
            else
            {
                if(count>1)
                {
                    res.push_back(s[low]);
                }
                count--;
                low++;
            }
        }
        return res;
    }
};