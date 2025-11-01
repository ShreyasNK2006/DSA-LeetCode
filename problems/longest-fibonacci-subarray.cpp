# Longest Fibonacci Subarray
Solved on 2025-10-11

class Solution {
public:
    int fibolen(vector<int>& nums,int ind)
    {
        int len =2;
        int i = ind+2;
        while(i<nums.size() && nums[i]==nums[i-1]+nums[i-2])
            {
                len++;
                i++;
            }
        return len;
    }
    int longestSubarray(vector<int>& nums){
    int len=2;
        for(int i=0;i<nums.size()-2;i+=(fibolen(nums,i)-1))
            {
                len = max(len,fibolen(nums,i));
            }
        return len;
    }
};