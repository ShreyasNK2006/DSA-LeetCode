/*
 * Problem 3660: Jump Game IX
 * URL     : https://leetcode.com/problems/jump-game-ix/
 * Solved  : 2026-05-07
 * Runtime : 12 ms
 * Memory  : 225.7 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n=nums.size();
        vector<int> lm(n);
        lm[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            lm[i]=max(lm[i-1],nums[i]);
        }
        vector<int> rm(n);
        rm[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            rm[i]=min(rm[i+1],nums[i]);
        }
        
        vector<int> res(n,0);
        res[n-1]=lm[n-1];
        for(int i=n-2;i>=0;i--)
        {
            if(lm[i]>rm[i+1])
            {
            res[i]=res[i+1];
            }
            else
            res[i]=lm[i];
        }
        return res;
    }
};