# Missing Number
Solved on 2025-09-01

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        for(;i<nums.size();)
        {
            if(i==nums[i])
            i++;
            else
            return i;
        }
        return i;
    }
};