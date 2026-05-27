/*
 * Problem 1674: Minimum Moves to Make Array Complementary
 * URL     : https://leetcode.com/problems/minimum-moves-to-make-array-complementary/
 * Solved  : 2026-05-13
 * Runtime : 24 ms
 * Memory  : 93.6 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n=nums.size();
        int h=2*limit;
        vector<int> range(h+2,0);
        for(int i=0;i<n/2;i++)
        {
            int x=min(nums[i],nums[n-1-i]);
            int y=max(nums[i],nums[n-1-i]);
            range[1+x]--;
            range[x+y]--;
            range[x+y+1]++;
            range[limit+y+1]++;
        }
        int minr=n;
        int curr_op=n;
        for(int i=2;i<=2*limit;i++)
        {
            curr_op+=range[i];
            minr=min(minr,curr_op);
        }
        return minr;
    }
};