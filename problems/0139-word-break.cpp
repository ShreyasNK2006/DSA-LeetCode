/*
 * Problem 0139: Word Break
 * URL     : https://leetcode.com/problems/word-break/
 * Solved  : 2026-04-21
 * Runtime : 18 ms
 * Memory  : 17 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    bool findvalidity(string &s,unordered_set<string>& st,vector<int>& dp,int ind)
    {
        int n=s.size();
        if(dp[ind]!=-1)
        return dp[ind];
        for(int i=ind;i<n;i++)
        {
            if(st.find(s.substr(ind,i-ind+1))!=st.end() && findvalidity(s,st,dp,i+1))
            return dp[ind]=1;
        }
        return dp[ind]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<int> dp(n+1,-1);
        dp[n]=1;
        unordered_set<string> st;
        for(int i=0;i<wordDict.size();i++)
        st.insert(wordDict[i]);
        return findvalidity(s,st,dp,0);

    }
};