# Count Subarrays With Majority Element I
Solved on 2025-11-08

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int tempcount=0,count=0,size;
        for(int i=0;i<nums.size();i++)
            {
                tempcount=0;
                for(int j=i;j<nums.size();j++)
                    {
                        if(nums[j]==target)
                            tempcount++;
                        size=(j-i+1)/2;
                        if(size<tempcount)
                            count++;
                    }
            }
        return count;
    }
};