/*
 * Problem 1871: Jump Game VII
 * URL     : https://leetcode.com/problems/jump-game-vii/
 * Solved  : 2026-05-25
 * Runtime : 15 ms
 * Memory  : 38.6 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.size();
        vector<int> f(n),pre(n);
        f[0]=1;
        for(int i=0;i<n;i++)
        {
            pre[i]=1;
        }
        for(int i=minJump;i<n;i++)
        {
            int right=i-minJump,left=i-maxJump;
            if(s[i]=='0')
            {
                int total = pre[right]-(left<=0?0:pre[left-1]);
                f[i]=(total!=0);
            }
            pre[i]=pre[i-1]+f[i];
        }
        return f[n-1];
    }
};