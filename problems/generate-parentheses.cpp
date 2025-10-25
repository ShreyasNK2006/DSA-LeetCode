# Generate Parentheses
Solved on 2025-10-03

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