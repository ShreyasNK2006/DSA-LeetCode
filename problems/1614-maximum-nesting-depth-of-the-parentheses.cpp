/*
 * Problem 1614: Maximum Nesting Depth of the Parentheses
 * URL     : https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
 * Solved  : 2026-09-28
 * Runtime : 0 ms
 * Memory  : 8.3 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int maxDepth(string s) {
        int depth =0;
        int open =0;
        for(auto x:s)
        {
            if(x=='(')
            open++;
            else if(x==')')
            open--;
            if(open>=depth)
            depth=open;
        }
        return depth;
    }
};