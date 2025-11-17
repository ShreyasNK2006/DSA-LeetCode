# Find the Smallest Divisor Given a Threshold
Solved on 2025-09-17

class Solution {
public:
    long long findsmall(vector<int> &nums,int div)
    {
        long long sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=(((long long)nums[i]+div-1)/div);
        }
        return sum; 
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1,high=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            high =max(high,nums[i]);
        }
        while(low<=high)
        {
            int mid=(low+high)/2;
            long long sum =findsmall(nums,mid);
            if(sum<=threshold)
            high=mid-1;
            else
            low=mid+1;
        }
        return low;
    }
};