/*
 * Problem 0022: Generate Parentheses
 * URL     : https://leetcode.com/problems/generate-parentheses/
 * Solved  : 2026-10-02
 * Runtime : 2 ms
 * Memory  : 15.8 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    void combinationgen(string curr,int open,int close,int n,vector<string>& res)
    {
        if(curr.length() == 2*n)
        {
            res.push_back(curr);
            return;
        }
        if(open<n)
        combinationgen(curr+'(',open+1,close,n,res);
        if(close<open)
        combinationgen(curr+')',open,close+1,n,res);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        combinationgen("",0,0,n,res);
        return res;
    }
};