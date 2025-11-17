# Capacity To Ship Packages Within D Days
Solved on 2025-09-17

class Solution {
public:
    int dayscalc(vector<int> &nums,int cap)
    {
        int time=1,temp=cap;
        for(int i=0;i<nums.size();)
        {
            if(nums[i]<=temp)
            {
                temp-=nums[i];
                i++;
            }
            else
            {
                time++;
                temp=cap;
            }
        }
        return time;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=weights[0],high=weights[0];
        for(int i=1;i<weights.size();i++)
        {
            high+=weights[i];
            low=max(low,weights[i]);
        }
        while(low<=high)
        {
            int mid=(low+high)/2;
            int time = dayscalc(weights,mid);
            if(time<=days)
            high=mid-1;
            else
            low= mid+1;
        }
        return low;
    }
};