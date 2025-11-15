# Binary Subarrays With Sum
Solved on 2025-11-12

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unsigned int count=0;
        int sum=0,left=0,right=0;
        int temp;
        int sumcopy;
        while(right<nums.size())
        {
            sum+=nums[right];
            while(sum>goal)
            {
                sum-=nums[left];
                left++;
            }
            temp=left;
            sumcopy =sum;
            while(sumcopy==goal && temp<=right)
            {
                count++;
                sumcopy-=nums[temp];
                temp++;
            }
             
            right++;
        }
        return count;
    }
};