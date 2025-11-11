# Maximum Alternating Sum of Squares
Solved on 2025-10-26

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
                int len = nums.size();
        for(int i=0;i<len;i++)
            {
                if(nums[i]<0)
                    nums[i]*=-1;
            }
        sort(nums.begin(),nums.end());
        long long sum=0;
        for(int i=0;i<len/2;i++)
            {
                sum-=(pow(nums[i],2));
            }
        for(int i=len/2;i<len;i++)
            {
                sum+=(pow(nums[i],2));
            }
        return sum;
    }
};