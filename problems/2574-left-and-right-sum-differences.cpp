/*
 * Problem 2574: Left and Right Sum Differences
 * URL     : https://leetcode.com/problems/left-and-right-sum-differences/
 * Solved  : 2026-06-06
 * Runtime : 0 ms
 * Memory  : 15.2 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int> leftsum(n,0),rightsum(n,0),res(n);
        for(int i=1;i<n;i++)
        {
            leftsum[i]+=leftsum[i-1];
            leftsum[i]+=nums[i-1];
        }
        for(int i=n-2;i>=0;i--)
        {
            rightsum[i]+=rightsum[i+1];
            rightsum[i]+=nums[i+1];
        }
        for(int i=0;i<n;i++)
        res[i]=abs(leftsum[i]-rightsum[i]);
        return res;
    }
};