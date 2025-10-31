# Single Element in a Sorted Array
Solved on 2025-09-14

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int val,i;
        for(i=0;i<nums.size()-1;i+=2)
        {
            if(nums[i] != nums[i+1])
            {
                val = nums[i];
                return val;
            }
        }  
        return nums[i];
    }
};