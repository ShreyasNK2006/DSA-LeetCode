/*
 * Problem 1048: Longest String Chain
 * URL     : https://leetcode.com/problems/longest-string-chain/
 * Solved  : 2026-04-05
 * Runtime : 47 ms
 * Memory  : 22.3 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](string &a,string &b){ return a.size()<b.size();});
        unordered_map<string,int> dp;
        int maxlen=1;
        for(auto word:words)
        {
            string prev;
            dp[word]=1;
            for(int i=0;i<word.size();i++)
            {
                prev= word.substr(0,i)+word.substr(i+1);
                if(dp.count(prev))
                {
                    dp[word]=max(dp[word],dp[prev]+1);
                    maxlen=max(dp[word],maxlen);
                }
            }
        }
        return maxlen;
    }
};