# Compute Alternating Sum
Solved on 2025-10-05

class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int asum=0;
        for(int i=0;i<nums.size();i++)
            {
                if(i%2==0)
                    asum+=nums[i];
                else
                    asum-=nums[i];
            }
        return asum;
            }
};