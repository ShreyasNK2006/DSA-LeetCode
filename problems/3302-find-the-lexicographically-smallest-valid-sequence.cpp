/*
 * Problem 3302: Find the Lexicographically Smallest Valid Sequence
 * URL     : https://leetcode.com/problems/find-the-lexicographically-smallest-valid-sequence/
 * Solved  : 2026-08-21
 * Runtime : 50 ms
 * Memory  : 111.2 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int m = word2.size(),n= word1.size();
        vector<int> dp(n+1,0);//
        for(int i=n-1;i>=0;i--)
        {
            if(dp[i+1]<m && word1[i]==word2[m-dp[i+1]-1])
            {
                dp[i]=dp[i+1]+1;
            }
            else
            dp[i]=dp[i+1];
            //cout<<dp[i]<<endl;
        }
        vector<int> res;
        int j=0;
        bool equate =true;
        for(int i=0;i<n && j<m;i++)
        {
            if(word1[i]==word2[j])
            {
                res.push_back(i);
                j++;
            }
            else if(dp[i]!=dp[i+1])
            {
                continue;
            }
            else if(dp[i]==dp[i+1] && equate && dp[i]>=(m-j-1))
            {
                res.push_back(i);
                j++;
                equate=false;
            }
        }
        if(j==m)
        return res;
        else
        return { };
    }
};