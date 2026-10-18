/*
 * Problem 4071: Minimum Rotations to Dial a Number II
 * URL     : https://leetcode.com/problems/minimum-rotations-to-dial-a-number-ii/
 * Solved  : 2026-10-04
 * Runtime : 15 ms
 * Memory  : 37 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int minRotations(int n, string s) {
        vector<int> suff(n,0);
        char curr=s[n-1];
        for(int i=n-2;i>=0;i--)
        {
            int f = min(abs(s[i]-curr),abs(10-abs(s[i]-curr)));
            curr=s[i];
            suff[i]=suff[i+1]+f;
        }
        int ans=suff[0]+ min(abs(s[n-1]-'0'),abs(10-abs(s[n-1]-'0')));;
        curr='0';
        int t=0;
        for(int i=0;i<n;i++)
        {
            int f = min(abs(s[i]-curr),abs(10-abs(s[i]-curr)));
            t+=f;
            if(i<n-1)
            ans = min(ans,t+suff[i+1]+min(abs(s[i]-s[n-1]),abs(10-abs(s[i]-s[n-1]))));
            curr=s[i];
        }
        ans=min(ans,t);
        return ans;
    }
};