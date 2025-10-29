# Word Break
Solved on 2025-10-11

class Solution {
public:
    bool compute(string &s,unordered_set<string> wordDict,int ind,vector<int> & dp)
    {
        if(ind == s.length())
        return true;
        if(dp[ind]!=-1)
        return dp[ind];
        for(int i=ind;i<s.length();i++)
        {
            string subs = s.substr(ind,i-ind+1);
            if(wordDict.count(subs)&& compute(s,wordDict,i+1,dp))
            return dp[ind]=true; 
        }
        return dp[ind]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        vector<int> dp(s.size(),-1);
        return compute(s,dict,0,dp);
    }
};