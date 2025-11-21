/*
 * Problem: Maximize Expression of Three Elements
 * Solved on: 2025-11-16
 * Runtime: 0 ms
 * Memory: 31.2 MB
*/

class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int res=0;
        res=nums[nums.size()-1]+nums[nums.size()-2]-nums[0];
        return res;
    }
};