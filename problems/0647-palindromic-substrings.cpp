/*
 * Problem 0647: Palindromic Substrings
 * URL     : https://leetcode.com/problems/palindromic-substrings/
 * Solved  : 2026-04-24
 * Runtime : 3 ms
 * Memory  : 8.6 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        //vector<vector<int>> dp(n,vector<int>(n,-1));
        int count=0;
        for(int i=0;i<n;i++)
        {
            count++;
            int lft=i-1,rht=i+1;
            while(lft>=0 && rht<=n-1)
            {
                if(s[lft]!=s[rht])
                break;
                else
                count++;
                lft--;
                rht++;
            }
        }
        for(int i=1;i<n;i++)
        {
            int lft=i-1,rht=i;
            while(lft>=0 && rht<=n-1)
            {
                if(s[lft]==s[rht])
                count++;
                else
                break;
                lft--;
                rht++;
            }
        }
        return count;
    }
};