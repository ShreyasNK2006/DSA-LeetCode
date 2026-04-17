/*
 * Problem 0132: Palindrome Partitioning II
 * URL     : https://leetcode.com/problems/palindrome-partitioning-ii/
 * Solved  : 2026-04-06
 * Runtime : 1764 ms
 * Memory  : 9.3 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    bool ispalindrome(int i,int j,string &s)
    {
        while(i<=j)
        {
            if(s[i]!=s[j])
            return false;
            i++;
            j--;
        }
        return true;
    }
    int minCut(string s) {
        int n=s.size();
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--)
        {
            int mincost=INT_MAX;
            for(int j=i;j<n;j++)
            {
                if(ispalindrome(i,j,s)==true)
                mincost=min(mincost,1+dp[j+1]);
            }
            if(mincost!=INT_MAX)
            dp[i]=mincost;
        }
        return dp[0]-1;
    }
};