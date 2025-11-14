# Minimum Moves to Equal Array Elements III
Solved on 2025-11-08

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int m=INT_MIN;
        for(int i=0;i<nums.size();i++)
            {
                m=max(m,nums[i]);
            }
        int minmove=0;
        for(int i=0;i<nums.size();i++)
            {
                minmove+=(m-nums[i]);
            }
        return minmove;
    }
};