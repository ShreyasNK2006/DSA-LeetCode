# Longest Subsequence With Non-Zero Bitwise XOR
Solved on 2025-10-05

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int res=0,zerocount=0;
        for(int ind=0;ind<nums.size();ind++)
            {
                    res^=nums[ind];
                    if(nums[ind]==0)
                        zerocount++;
            }
        if(res!=0)
            return nums.size();
        if(zerocount==nums.size())
            return 0;
            return nums.size()-1;
    }
    
};